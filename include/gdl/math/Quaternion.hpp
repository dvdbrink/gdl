#ifndef GDL_MATH_QUATERNION_HPP
#define GDL_MATH_QUATERNION_HPP

#include <gdl/math/Math.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/math/Vector3.hpp>

#include <ostream>

namespace gdl
{
namespace math
{

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;
public:
	Quaternion();
	Quaternion(const float x, const float y, const float z, const float w);
	Quaternion(const Quaternion& rhs);
	Quaternion(Quaternion&& rhs);
	Quaternion& operator=(const Quaternion& rhs);
	Quaternion& operator=(Quaternion&& rhs);
	math::Matrix4f getMatrix();
};

Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);

math::Vector3f operator*(const Quaternion& q, const math::Vector3f& v);

Quaternion operator/(const Quaternion& lhs, const float rhs);

float dot(const Quaternion& lhs, const Quaternion& rhs);

math::Vector3f operator*(const math::Vector3f& v, const Quaternion& q);

Quaternion rotate(const Quaternion& in, const float angle, const math::Vector3f& unit);

std::ostream& operator<<(std::ostream& out, const Quaternion& rhs);

#include <gdl/math/Quaternion.inl>

}
}

#endif // GDL_MATH_QUATERNION_HPP
