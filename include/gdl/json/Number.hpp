#ifndef GDL_JSON_NUMBER_HPP
#define GDL_JSON_NUMBER_HPP

#include <gdl/json/Value.hpp>

namespace gdl
{
namespace json
{

class Number : public Value
{
public:
	Number(const Uint32 i) : i(i) {}
	virtual ~Number() {}

	Int32 asInt() const override
	{
		return i;
	}

	Uint32 asUint() const override
	{
		return reinterpret_cast<Uint32>(i);
	}

private:
	std::ostream& ostream(std::ostream& out) const override
	{
		return out << i;
	}

private:
	Uint32 i;
};

}
}

#endif // GDL_JSON_NUMBER_HPP
