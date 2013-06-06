#ifndef GDL_EVENT_HPP
#define GDL_EVENT_HPP

#include <functional>
#include <vector>

namespace gdl
{
namespace detail
{

template <typename Event>
class EventBroadcaster
{
public:
    virtual ~EventBroadcaster() {}
	typedef std::function<void(const Event&)> Connection;
	void connect(Connection&& connection)
	{
		connections.push_back(std::move(connection));
	}
	void signal(const Event& event)
	{
		for (const auto& connection : connections)
		{
			connection(event);
		}
	}
private:
	std::vector<Connection> connections;
};

template <typename T> struct function_traits
	: public function_traits<decltype(&T::operator())> {};

template <typename C, typename R, typename A>
struct function_traits<R(C::*)(const A&) const>
{
	typedef A type;
};

}

template <typename... Events>
class EventBroadcaster : detail::EventBroadcaster<Events>...
{
public:
	virtual ~EventBroadcaster() {}
	template <typename Connection>
	void connect(Connection&& connection)
	{
        typedef typename detail::function_traits<Connection>::type Event;
        detail::EventBroadcaster<Event>& impl = *this;
		impl.connect(std::move(connection));
	}
	template <typename Event>
	void signal(const Event& event)
	{
        detail::EventBroadcaster<Event>& impl = *this;
		impl.signal(event);
    }
};

}

#endif // GDL_EVENT_HPP
