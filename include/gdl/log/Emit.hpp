#ifndef GDL_LOG_EMIT_HPP
#define GDL_LOG_EMIT_HPP

#include <gdl/Singleton.hpp>
#include <gdl/log/Level.hpp>
#include <gdl/log/Output.hpp>

namespace gdl
{
namespace log
{

template<typename Level, typename Output>
inline Output& out()
{
	return Singleton<Output>::get()
		<< Level::backgroundColor()
		<< Level::foregroundColor()
		<< Level::description()
		<< ForegroundColor::DEFAULT
		<< BackgroundColor::DEFAULT
		<< " ";
}

template<typename Level>
inline DefaultOutput& out()
{
    return out<Level, DefaultOutput>();
}

inline DefaultOutput& out()
{
    return out<DefaultLevel, DefaultOutput>();
}

}
}

#endif // GDL_LOG_EMIT_HPP
