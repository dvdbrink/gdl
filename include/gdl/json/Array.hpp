#ifndef GDL_JSON_ARRAY_HPP
#define GDL_JSON_ARRAY_HPP

#include <gdl/json/Value.hpp>

#include <vector>
#include <memory>
#include <stdexcept>

namespace gdl
{
namespace json
{

class Array :
	public Value,
	public std::vector<std::shared_ptr<Value>>
{
public:
	Array() {}
	virtual ~Array() {}

	const Value& operator[](std::size_t index) const override
	{
		try
		{
			return *this->at(index);
		}
		catch (...)
		{
			throw std::runtime_error("json::Value does not exist");
		}
	}

private:
	std::ostream& ostream(std::ostream& out) const override
	{
		out << "[ ";
		for (const auto i : *this)
		{
			out << (*i) << ",";
		}
		return out << " ]";
	}
};

}
}

#endif // GDL_JSON_ARRAY_HPP
