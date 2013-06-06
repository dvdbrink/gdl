#ifndef GDL_LOG_OUTPUT_HPP
#define GDL_LOG_OUTPUT_HPP

#include <gdl/log/Color.hpp>

#include <iostream>

namespace gdl
{
namespace log
{

enum Manipulator
{
	ENDL = '\n',
	TAB  = '\t'
};

class ConsoleOutput
{
public:
	ConsoleOutput() {}
	virtual ~ConsoleOutput() {}
	ConsoleOutput& operator<<(const ForegroundColor c)
	{
		*this << "\033[" << static_cast<unsigned short>(c) << 'm';
		return *this;
	}
	ConsoleOutput& operator<<(const BackgroundColor c)
	{
		*this << "\033[" << static_cast<unsigned short>(c) << 'm';
		return *this;
	}
	ConsoleOutput& operator<<(const Manipulator m)
	{
		*this << static_cast<char>(m);
		return *this;
	}
	template<typename T>
	ConsoleOutput& operator<<(const T& t)
	{
		std::cout << t;
		return *this;
	}
};

typedef ConsoleOutput DefaultOutput;

}
}

#endif // GDL_LOG_OUTPUT_HPP
