#ifndef GDL_MATH_HPP
#define GDL_MATH_HPP

#include <cmath>

namespace gdl
{
namespace math
{

const double PI = std::atan(1.0)*4;

inline float radians(const float& degrees)
{
	return degrees * (static_cast<float>(PI) / 180);
}

inline float degrees(const float& radians)
{
	return radians * (180 / static_cast<float>(PI));
}

}
}

#endif // GDL_MATH_HPP
