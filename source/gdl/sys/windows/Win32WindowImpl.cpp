#include "Win32WindowImpl.hpp"

#include <gdl/log/Emit.hpp>

namespace gdl
{
namespace sys
{

const std::string Win32WindowImpl::CLASS_NAME = "GDLWin32WindowImpl";

Win32WindowImpl::Win32WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height) :
	WindowImpl(title, left, top, width, height),
	mousePositionX(0), mousePositionY(0)
{
	::WNDCLASS window;
    window.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	window.lpfnWndProc		= &Win32WindowImpl::onEvent;
	window.cbClsExtra		= 0;
	window.cbWndExtra		= 0;
	window.hInstance		= ::GetModuleHandle(0);
	window.hIcon			= 0;
	window.hCursor			= ::LoadCursor(NULL, IDC_ARROW);;
	window.hbrBackground	= 0;
	window.lpszMenuName		= 0;
	window.lpszClassName	= CLASS_NAME.c_str();
	if (!::RegisterClass(&window))
	{
		::MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	}

	handle = CreateWindow(
        CLASS_NAME.c_str(),
        title.c_str(),
		WS_OVERLAPPEDWINDOW,
        left, top,
		width, height,
		nullptr,
		nullptr,
		::GetModuleHandle(0),
		this);
	if (!handle)
	{
		::MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	}

	ShowWindow(handle, SW_SHOW);

	rid[0].usUsagePage = 1;
	rid[0].usUsage = 2;
	rid[0].dwFlags = 0;
	rid[0].hwndTarget = nullptr;

	rid[1].usUsagePage = 1;
	rid[1].usUsage = 6;
	rid[1].dwFlags = 0;
	rid[1].hwndTarget = nullptr;

	if (RegisterRawInputDevices((PCRAWINPUTDEVICE)rid, 2, sizeof(rid[0])) == FALSE)
	{
        log::out<log::Error>() << "RegisterRawInputDevices failed. (" << GetLastError() << ")" << log::ENDL;
	}
}

Win32WindowImpl::~Win32WindowImpl()
{
	::DestroyWindow(handle);
	::UnregisterClass(CLASS_NAME.c_str(), ::GetModuleHandle(NULL));
}

void Win32WindowImpl::setTitle(const std::string& title)
{
	SetWindowText(handle, title.c_str());
}

void Win32WindowImpl::setMouseVisible(bool visible)
{
	::ShowCursor(visible);
}

void Win32WindowImpl::setMousePosition(int left, int top)
{
	::SetCursorPos(left, top);
}

void Win32WindowImpl::processEvents()
{
	MSG message;
	while (PeekMessage(&message, handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

LRESULT CALLBACK Win32WindowImpl::processEvent(Uint32 message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY: handleCloseEvent();       break;
		case WM_INPUT:	 handleInputEvent(lParam); break;
	}

	return ::DefWindowProc(this->handle, message, wParam, lParam);
}

void Win32WindowImpl::handleCloseEvent()
{
	::PostQuitMessage(0);
	Closed closed;
	signal(closed);
}

void Win32WindowImpl::handleInputEvent(LPARAM lParam)
{
	unsigned int bufferSize;
	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, nullptr, &bufferSize, sizeof(RAWINPUTHEADER));
	BYTE *buffer = new BYTE[bufferSize];
	GetRawInputData((HRAWINPUT)lParam, RID_INPUT, (LPVOID)buffer, &bufferSize, sizeof(RAWINPUTHEADER));

	RAWINPUT *raw = (RAWINPUT*) buffer;
	if (raw->header.dwType == RIM_TYPEKEYBOARD)
	{
		USHORT keyCode = raw->data.keyboard.VKey;
		bool keyUp = raw->data.keyboard.Flags & RI_KEY_BREAK;

		Keyboard::Key key = map(keyCode);
		if (keyUp)
		{
			Keyboard::KeyReleased keyReleased;
			keyReleased.key = key;
			keyReleased.alt = HIWORD(GetAsyncKeyState(VK_MENU))!=0;
			keyReleased.control = HIWORD(GetAsyncKeyState(VK_CONTROL))!=0;
			keyReleased.shift = HIWORD(GetAsyncKeyState(VK_SHIFT))!=0;
			signal(keyReleased);
		}
		else
		{
			Keyboard::KeyPressed keyPressed;
			keyPressed.key = key;
			keyPressed.alt = HIWORD(GetAsyncKeyState(VK_MENU))!=0;
			keyPressed.control = HIWORD(GetAsyncKeyState(VK_CONTROL))!=0;
			keyPressed.shift = HIWORD(GetAsyncKeyState(VK_SHIFT))!=0;
			signal(keyPressed);
		}

		std::string str = toString(key);
		if (keyUp && str.size() > 0)
		{
			Keyboard::TextEntered textEntered;
			textEntered.text = str;
			signal(textEntered);
		}
	}
	if (raw->header.dwType == RIM_TYPEMOUSE)
	{
		long mouseMotionX = raw->data.mouse.lLastX;
		long mouseMotionY = raw->data.mouse.lLastY;
		if (mouseMotionX !=0 || mouseMotionY != 0)
		{
			mousePositionX += mouseMotionX;
			mousePositionY += mouseMotionY;

			Mouse::Motion motion;
			motion.x = mousePositionX;
			motion.y = mousePositionY;
			signal(motion);
		}

		if (raw->data.mouse.ulButtons & RI_MOUSE_LEFT_BUTTON_UP)
		{
			Mouse::ButtonReleased buttonReleased;
			buttonReleased.button = Mouse::Button::Left;
			signal(buttonReleased);
		}
		if (raw->data.mouse.ulButtons & RI_MOUSE_LEFT_BUTTON_DOWN)
		{
			Mouse::ButtonPressed buttonPressed;
			buttonPressed.button = Mouse::Button::Left;
			signal(buttonPressed);
		}
		if (raw->data.mouse.ulButtons & RI_MOUSE_MIDDLE_BUTTON_UP) 
		{
			Mouse::ButtonReleased buttonReleased;
			buttonReleased.button = Mouse::Button::Middle;
			signal(buttonReleased);
		}
		if (raw->data.mouse.ulButtons & RI_MOUSE_MIDDLE_BUTTON_DOWN)
		{
			Mouse::ButtonPressed buttonPressed;
			buttonPressed.button = Mouse::Button::Middle;
			signal(buttonPressed);
		}
		if (raw->data.mouse.ulButtons & RI_MOUSE_RIGHT_BUTTON_UP)
		{
			Mouse::ButtonReleased buttonReleased;
			buttonReleased.button = Mouse::Button::Right;
			signal(buttonReleased);
		}
		if (raw->data.mouse.ulButtons & RI_MOUSE_RIGHT_BUTTON_DOWN)
		{
			Mouse::ButtonPressed buttonPressed;
			buttonPressed.button = Mouse::Button::Right;
			signal(buttonPressed);
		}
	}

	delete[] buffer;
}

Keyboard::Key Win32WindowImpl::map(unsigned short keyCode)
{
	switch (keyCode)
	{
		case 'A': return Keyboard::Key::A;
		case 'B': return Keyboard::Key::B;
		case 'C': return Keyboard::Key::C;
		case 'D': return Keyboard::Key::D;
		case 'E': return Keyboard::Key::E;
		case 'F': return Keyboard::Key::F;
		case 'G': return Keyboard::Key::G;
		case 'H': return Keyboard::Key::H;
		case 'I': return Keyboard::Key::I;
		case 'J': return Keyboard::Key::J;
		case 'K': return Keyboard::Key::K;
		case 'L': return Keyboard::Key::L;
		case 'M': return Keyboard::Key::M;
		case 'N': return Keyboard::Key::N;
		case 'O': return Keyboard::Key::O;
		case 'P': return Keyboard::Key::P;
		case 'Q': return Keyboard::Key::Q;
		case 'R': return Keyboard::Key::R;
		case 'S': return Keyboard::Key::S;
		case 'T': return Keyboard::Key::T;
		case 'U': return Keyboard::Key::U;
		case 'V': return Keyboard::Key::V;
		case 'W': return Keyboard::Key::W;
		case 'X': return Keyboard::Key::X;
		case 'Y': return Keyboard::Key::Y;
		case 'Z': return Keyboard::Key::Z;

		case VK_UP:   	return Keyboard::Key::Up;
		case VK_DOWN: 	return Keyboard::Key::Down;
		case VK_LEFT:	return Keyboard::Key::Left;
		case VK_RIGHT:  return Keyboard::Key::Right;

		case VK_OEM_3: return Keyboard::Key::Tilde;

		default: return Keyboard::Key::Unknown;
	}
}

std::string Win32WindowImpl::toString(const Keyboard::Key& key)
{
	switch (key)
	{
		case Keyboard::Key::A: return "a";
		case Keyboard::Key::B: return "b";
		case Keyboard::Key::C: return "c";
		case Keyboard::Key::D: return "d";
		case Keyboard::Key::E: return "e";
		case Keyboard::Key::F: return "f";
		case Keyboard::Key::G: return "g";
		case Keyboard::Key::H: return "h";
		case Keyboard::Key::I: return "i";
		case Keyboard::Key::J: return "j";
		case Keyboard::Key::K: return "k";
		case Keyboard::Key::L: return "l";
		case Keyboard::Key::M: return "m";
		case Keyboard::Key::N: return "n";
		case Keyboard::Key::O: return "o";
		case Keyboard::Key::P: return "p";
		case Keyboard::Key::Q: return "q";
		case Keyboard::Key::R: return "r";
		case Keyboard::Key::S: return "s";
		case Keyboard::Key::T: return "t";
		case Keyboard::Key::U: return "u";
		case Keyboard::Key::V: return "v";
		case Keyboard::Key::W: return "w";
		case Keyboard::Key::X: return "x";
		case Keyboard::Key::Y: return "y";
		case Keyboard::Key::Z: return "z";

		case Keyboard::Key::Space: return " ";
		case Keyboard::Key::Tilde: return "~";

		default: return "";
	}
}

LRESULT CALLBACK Win32WindowImpl::onEvent(WindowHandle handle, Uint32 message, WPARAM wParam, LPARAM lParam)
{
	Win32WindowImpl* window;

	if (message == WM_NCCREATE)
	{
		window = reinterpret_cast<Win32WindowImpl*>((reinterpret_cast<LPCREATESTRUCT>(lParam))->lpCreateParams);
		::SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
		window->handle = handle;
	}
	else
	{
		window = reinterpret_cast<Win32WindowImpl*>(::GetWindowLongPtr(handle, GWLP_USERDATA));
	}

	if (window)
	{
		return window->processEvent(message, wParam, lParam);
	}
	else
	{
		return ::DefWindowProc(handle, message, wParam, lParam);
	}
}

}
}
