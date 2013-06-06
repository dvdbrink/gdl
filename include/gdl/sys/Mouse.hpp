#ifndef GDL_SYS_MOUSE_HPP
#define GDL_SYS_MOUSE_HPP

namespace gdl
{
namespace sys
{
namespace Mouse
{

enum class Button
{
	Unknown,
	Left,
	Middle,
	Right
};

struct Motion
{
    int x;
    int y;
    int dx;
    int dy;
};

struct ButtonPressed
{
	Button button;
    Motion motion;
};

struct ButtonReleased
{
	Button button;
    Motion motion;
};

}
}
}

#endif // GDL_SYS_MOUSE_HPP
