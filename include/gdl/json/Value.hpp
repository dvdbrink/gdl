#ifndef GDL_JSON_VALUE_HPP
#define GDL_JSON_VALUE_HPP

#include <gdl/Types.hpp>

#include <string>
#include <ostream>
#include <stdexcept>

namespace gdl
{
namespace json
{

class Value
{
public:
	Value() {}
	virtual ~Value() {}

	virtual const Value& operator[](const std::string&) const
	{
		throw std::runtime_error("json::Value does not exist");
	}

	virtual const Value& operator[](std::size_t) const
	{
		throw std::runtime_error("json::Value does not exist");
	}

	virtual std::string asString() const
	{
		throw std::runtime_error("json::Value is not a string");
	}

	virtual Int32 asInt() const
	{
		throw std::runtime_error("json::Value is not a int");
	}

	virtual Uint32 asUint() const
	{
		throw std::runtime_error("json::Value is not a uint");
	}

	virtual Int32 asFloat() const
	{
		throw std::runtime_error("json::Value is not a int");
	}

	virtual Int32 asDouble() const
	{
		throw std::runtime_error("json::Value is not a int");
	}

	virtual bool asBool() const
	{
		throw std::runtime_error("json::Value is not a bool");
	}

private:
	friend inline std::ostream& operator<<(std::ostream& out, const Value& value);
	virtual std::ostream& ostream(std::ostream&) const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const Value& value)
{
    value.ostream(out);
    return out;
}

}
}

#endif // GDL_JSON_VALUE_HPP
