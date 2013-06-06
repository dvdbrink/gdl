#ifndef GDL_LOG_COLOR_HPP
#define GDL_LOG_COLOR_HPP

namespace gdl
{
namespace log
{

enum class ForegroundColor
{
	DEFAULT = 0,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37
};

enum class BackgroundColor
{
	DEFAULT = 0,
	BLACK = 40,
	RED = 41,
	GREEN = 42,
	YELLOW = 43,
	BLUE = 44,
	MAGENTA = 45,
	CYAN = 46,
	WHITE = 47
};

}
}

#endif // GDL_LOG_COLOR_HPP
