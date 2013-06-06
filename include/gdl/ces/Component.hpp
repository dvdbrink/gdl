#ifndef GDL_CES_COMPONENT_HPP
#define GDL_CES_COMPONENT_HPP

#include <gdl/Types.hpp>

#include <bitset>

namespace gdl
{
namespace ces
{

using ComponentMask = std::bitset<32>;

struct BaseComponent
{
public:
	typedef Uint64 Family;

protected:
	static Family nextFamily;
};

template <typename Derived>
struct Component : public BaseComponent
{
public:
	static Family family() {
		static Family family = nextFamily++;
		return family;
	}
};

}
}

#endif // GDL_CES_COMPONENT_HPP
