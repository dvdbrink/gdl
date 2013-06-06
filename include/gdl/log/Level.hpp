#ifndef GDL_LOG_LEVEL_HPP
#define GDL_LOG_LEVEL_HPP

#include <gdl/log/Color.hpp>

#include <string>

namespace gdl
{
namespace log
{

enum class Level
{
	DEBUG,
	ERROR,
	FATAL,
	INFO,
	TRACE,
	WARN
};

class Debug
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::GREEN;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::DEFAULT;
	}
	static Level level()
	{
		return Level::DEBUG;
	}
	static const std::string description()
	{
		return "[DEBUG]";
	}
};

class Error
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::RED;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::DEFAULT;
	}
	static Level level()
	{
		return Level::ERROR;
	}
	static const std::string description()
	{
		return "[ERROR]";
	}
};

class Fatal
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::WHITE;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::RED;
	}
	static Level level()
	{
		return Level::FATAL;
	}
	static const std::string description()
	{
		return "[FATAL]";
	}
};

class Info
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::CYAN;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::DEFAULT;
	}
	static Level level()
	{
		return Level::INFO;
	}
	static const std::string description()
	{
		return "[INFO]";
	}
};

class Trace
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::MAGENTA;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::DEFAULT;
	}
	static Level level()
	{
		return Level::TRACE;
	}
	static const std::string description()
	{
		return "[TRACE]";
	}
};

class Warn
{
public:
	static ForegroundColor foregroundColor()
	{
		return ForegroundColor::YELLOW;
	}
	static BackgroundColor backgroundColor()
	{
		return BackgroundColor::DEFAULT;
	}
	static Level level()
	{
		return Level::WARN;
	}
	static const std::string description()
	{
		return "[WARN]";
	}
};

typedef Debug DefaultLevel;

}
}

#endif // GDL_LOG_LEVEL_HPP
