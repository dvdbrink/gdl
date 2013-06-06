#ifndef GDL_JSON_BOOL_HPP
#define GDL_JSON_BOOL_HPP

#include <gdl/json/Value.hpp>

namespace gdl
{
namespace json
{

class Boolean : public Value
{
public:
	Boolean(const bool b) : b(b) {}
	virtual ~Boolean() {}

	bool asBool() const override
	{
		return b;
	}

private:
	std::ostream& ostream(std::ostream& out) const override
	{
		return out << b;
	}

private:
	bool b;
};

}
}

#endif // GDL_JSON_BOOL_HPP
