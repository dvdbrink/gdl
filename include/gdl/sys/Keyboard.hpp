#ifndef GDL_SYS_KEYBOARD_HPP
#define GDL_SYS_KEYBOARD_HPP

#include <string>

namespace gdl
{
namespace sys
{
namespace Keyboard
{

enum class Key
{
	Unknown = 0,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Left,
	Right,
	Up,
	Down,
	Tilde,
	Enter,
    Space,
    Backspace
};

struct KeyPressed
{
	Key key;
	bool alt;
	bool control;
	bool shift;
};

struct KeyPressedRepeat
{
	Key key;
	bool alt;
	bool control;
	bool shift;
};

struct KeyReleased
{
	Key key;
	bool alt;
	bool control;
	bool shift;
};

struct TextEntered
{
	std::string text;
};

}
}
}

#endif // GDL_SYS_KEYBOARD_HPP
