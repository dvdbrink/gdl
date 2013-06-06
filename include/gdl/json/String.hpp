#ifndef GDL_JSON_STRING_HPP
#define GDL_JSON_STRING_HPP

#include <gdl/json/Value.hpp>

namespace gdl
{
namespace json
{

class String : public Value
{
public:
	String(const std::string& str) : s(str) {}
	virtual ~String() {}

	std::string asString() const override
	{
		return s;
	}

private:
	std::ostream& ostream(std::ostream& out) const override
	{
		return out << s;
	}

private:
	std::string s;
};

}
}

#endif // GDL_JSON_STRING_HPP
