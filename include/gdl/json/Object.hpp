#ifndef GDL_JSON_OBJECT_HPP
#define GDL_JSON_OBJECT_HPP

#include <gdl/json/Value.hpp>

#include <unordered_map>
#include <memory>

namespace gdl
{
namespace json
{

class Object :
	public Value,
	public std::unordered_map<std::string, std::shared_ptr<Value>>
{
public:
	Object() {}
	virtual ~Object() {}

	const Value& operator[](const std::string& name) const override
	{
		try
		{
			return *this->at(name);
		}
		catch (...)
		{
			throw std::runtime_error("json::Value does not exist");
		}
	}

private:
	std::ostream& ostream(std::ostream& out) const override
	{
		out << "{" << std::endl;
		for (const auto i : *this)
		{
			out << " " << i.first << ": " << (*i.second) << "," << std::endl;
		}
		return out << "}";
	}
};

}
}

#endif // GDL_JSON_OBJECT_HPP
