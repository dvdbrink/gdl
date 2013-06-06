#include "X11WindowImpl.hpp"

#include <X11/Xutil.h>
#include <X11/keysym.h>

#include <X11/Xlib.h>

namespace gdl
{
namespace sys
{

static ::Atom closeEventAtom;

Bool checkEvent(::Display*, ::XEvent* event, ::XPointer userData)
{
	return event->xany.window == reinterpret_cast< ::Window >(userData);
}

X11WindowImpl::X11WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height) :
    WindowImpl(title, left, top, width, height),
    previousMouseX(0),
    previousMouseY(0)
{
	::XSetWindowAttributes attributes;
	attributes.event_mask = StructureNotifyMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask;

	handle.display = ::XOpenDisplay(nullptr);
	handle.screen = DefaultScreen(handle.display);
	handle.window = ::XCreateWindow(
		handle.display,
		RootWindow(handle.display, handle.screen),
		left, top,
		width, height,
		0,
		DefaultDepth(handle.display, handle.screen),
		InputOutput,
		DefaultVisual(handle.display, handle.screen),
		CWEventMask,
		&attributes);

	setTitle(title);

	closeEventAtom = ::XInternAtom(handle.display, "WM_DELETE_WINDOW", false);
	::XSetWMProtocols(handle.display, handle.window, &closeEventAtom, 1);

	::XMapWindow(handle.display, handle.window);
	::XMoveWindow(handle.display, handle.window, left, top);
	::XFlush(handle.display);

	Pixmap cursorPixmap = ::XCreatePixmap(handle.display, handle.window, 1, 1, 1);
	GC graphicsContext = ::XCreateGC(handle.display, cursorPixmap, 0, NULL);
	::XDrawPoint(handle.display, cursorPixmap, graphicsContext, 0, 0);
	::XFreeGC(handle.display, graphicsContext);

	XColor color;
	color.flags = DoRed | DoGreen | DoBlue;
	color.red = color.blue = color.green = 0;
	hiddenCursor = ::XCreatePixmapCursor(handle.display, cursorPixmap, cursorPixmap, &color, &color, 0, 0);

	::XFreePixmap(handle.display, cursorPixmap);
}

X11WindowImpl::~X11WindowImpl()
{
	if (hiddenCursor)
	{
		setMouseVisible(true);
		::XFreeCursor(handle.display, hiddenCursor);
	}

	if (handle.window)
	{
		::XDestroyWindow(handle.display, handle.window);
		::XFlush(handle.display);
	}

	if (handle.display)
	{
		::XCloseDisplay(handle.display);
	}
}

void X11WindowImpl::setTitle(const std::string& title)
{
	::XStoreName(handle.display, handle.window, title.c_str());
}


void X11WindowImpl::setMouseVisible(bool visible)
{
	::XDefineCursor(handle.display, handle.window, visible ? None : hiddenCursor);
	::XFlush(handle.display);
}

void X11WindowImpl::setMousePosition(int left, int top)
{
	::XWarpPointer(handle.display, None, RootWindow(handle.display, handle.screen), 0, 0, 0, 0, left, top);
	::XFlush(handle.display);
}

void X11WindowImpl::processEvents()
{
	::XEvent event;
	while (::XCheckIfEvent(handle.display, &event, &checkEvent, reinterpret_cast< ::XPointer >(handle.window)))
	{
		switch (event.type)
		{
			case ClientMessage: handleClientMessage(event);				break;
			case KeyPress: 		handleKeyPressEvent(event);				break;
			case KeyRelease: 	handleKeyReleaseEvent(event);			break;
			case ButtonPress: 	handleMouseButtonPressEvent(event);		break;
			case ButtonRelease: handleMouseButtonReleaseEvent(event);	break;
			case MotionNotify: 	handleMouseMotionEvent(event);  		break;
		}
	}
}

void X11WindowImpl::handleClientMessage(const ::XEvent& event)
{
	if (event.xclient.data.l[0] == static_cast<long>(closeEventAtom))
	{
		Closed closed;
		signal(closed);
	}
}

void X11WindowImpl::handleKeyPressEvent(const ::XEvent& event)
{
	Keyboard::KeyPressed keyPressed;
	keyPressed.key = keyFromXEvent(event);
	keyPressed.alt = event.xkey.state & Mod1Mask;
	keyPressed.control = event.xkey.state & ControlMask;
	keyPressed.shift = event.xkey.state & ShiftMask;
	signal(keyPressed);

	Keyboard::TextEntered textEntered;
	textEntered.text = stringFromXEvent(event);
	if (textEntered.text[0] >= 32 && textEntered.text[0] < 127)
	{
		signal(textEntered);
	}
}

void X11WindowImpl::handleKeyReleaseEvent(::XEvent& event)
{
	bool isRetriggered = false;
	if (::XEventsQueued(handle.display, QueuedAfterReading))
	{
		::XEvent nextEvent;
		::XPeekEvent(handle.display, &nextEvent);
		if (nextEvent.type == KeyPress && nextEvent.xkey.time == event.xkey.time && nextEvent.xkey.keycode == event.xkey.keycode)
		{
			Keyboard::KeyPressedRepeat keyPressedRepeat;
			keyPressedRepeat.key = keyFromXEvent(event);
			keyPressedRepeat.alt = event.xkey.state & Mod1Mask;
			keyPressedRepeat.control = event.xkey.state & ControlMask;
			keyPressedRepeat.shift = event.xkey.state & ShiftMask;
			signal(keyPressedRepeat);

			// Delete retriggered KeyPress event
			::XNextEvent(handle.display, &event);
			isRetriggered = true;
		}
	}
	if (!isRetriggered)
	{
		Keyboard::KeyReleased keyReleased;
		keyReleased.key = keyFromXEvent(event);
		keyReleased.alt = event.xkey.state & Mod1Mask;
		keyReleased.control = event.xkey.state & ControlMask;
		keyReleased.shift = event.xkey.state & ShiftMask;
		signal(keyReleased);
	}
}

void X11WindowImpl::handleMouseButtonPressEvent(const ::XEvent& event)
{
	Mouse::ButtonPressed buttonPressed;
	buttonPressed.button = map(event.xbutton.button);
    buttonPressed.motion.x = event.xmotion.x;
    buttonPressed.motion.y = event.xmotion.y;
    buttonPressed.motion.dx = event.xmotion.x - previousMouseX;
    buttonPressed.motion.dy = event.xmotion.y - previousMouseY;
    previousMouseX =  event.xmotion.x;
    previousMouseY =  event.xmotion.y;
	signal(buttonPressed);
}

void X11WindowImpl::handleMouseButtonReleaseEvent(const ::XEvent& event)
{
	Mouse::ButtonReleased buttonReleased;
	buttonReleased.button = map(event.xbutton.button);
    buttonReleased.motion.x = event.xmotion.x;
    buttonReleased.motion.y = event.xmotion.y;
    buttonReleased.motion.dx = event.xmotion.x - previousMouseX;
    buttonReleased.motion.dy = event.xmotion.y - previousMouseY;
    previousMouseX =  event.xmotion.x;
    previousMouseY =  event.xmotion.y;
	signal(buttonReleased);
}

void X11WindowImpl::handleMouseMotionEvent(const ::XEvent& event)
{
	Mouse::Motion motion;
	motion.x = event.xmotion.x;
	motion.y = event.xmotion.y;
    motion.dx = event.xmotion.x - previousMouseX;
    motion.dy = event.xmotion.y - previousMouseY;
    previousMouseX =  event.xmotion.x;
    previousMouseY =  event.xmotion.y;
	signal(motion);
}

Keyboard::Key X11WindowImpl::keyFromXEvent(const ::XEvent& event)
{
	KeySym symbol;
	static XComposeStatus keyboard;
	::XLookupString(const_cast<XKeyEvent*>(&event.xkey), 0, 0, &symbol, &keyboard);
	return map(symbol);
}

std::string X11WindowImpl::stringFromXEvent(const ::XEvent& event)
{
	char buffer[32];
	static XComposeStatus keyboard;
	::XLookupString(const_cast<XKeyEvent*>(&event.xkey), buffer, sizeof(buffer), 0, &keyboard);
	return std::string(buffer);
}

Keyboard::Key X11WindowImpl::map(const ::KeySym& key)
{
	::KeySym lower, upper;
	::XConvertCase(key, &lower, &upper);

	switch (upper)
	{
		case XK_A: return Keyboard::Key::A;
		case XK_B: return Keyboard::Key::B;
		case XK_C: return Keyboard::Key::C;
		case XK_D: return Keyboard::Key::D;
		case XK_E: return Keyboard::Key::E;
		case XK_F: return Keyboard::Key::F;
		case XK_G: return Keyboard::Key::G;
		case XK_H: return Keyboard::Key::H;
		case XK_I: return Keyboard::Key::I;
		case XK_J: return Keyboard::Key::J;
		case XK_K: return Keyboard::Key::K;
		case XK_L: return Keyboard::Key::L;
		case XK_M: return Keyboard::Key::M;
		case XK_N: return Keyboard::Key::N;
		case XK_O: return Keyboard::Key::O;
		case XK_P: return Keyboard::Key::P;
		case XK_Q: return Keyboard::Key::Q;
		case XK_R: return Keyboard::Key::R;
		case XK_S: return Keyboard::Key::S;
		case XK_T: return Keyboard::Key::T;
		case XK_U: return Keyboard::Key::U;
		case XK_V: return Keyboard::Key::V;
		case XK_W: return Keyboard::Key::W;
		case XK_X: return Keyboard::Key::X;
		case XK_Y: return Keyboard::Key::Y;
		case XK_Z: return Keyboard::Key::Z;

		case XK_Up:   return Keyboard::Key::Up;
		case XK_Down: return Keyboard::Key::Down;

		case XK_dead_grave: return Keyboard::Key::Tilde;
        case XK_Return:     return Keyboard::Key::Enter;
        case XK_KP_Enter:   return Keyboard::Key::Enter;
        case XK_BackSpace:   return Keyboard::Key::Backspace;

		default: return Keyboard::Key::Unknown;
	}
}

Mouse::Button X11WindowImpl::map(const unsigned int button)
{
	switch (button)
	{
		case 1: return Mouse::Button::Left;
		case 2: return Mouse::Button::Middle;
		case 3: return Mouse::Button::Right;

		default: return Mouse::Button::Unknown;
	}
}

}
}
