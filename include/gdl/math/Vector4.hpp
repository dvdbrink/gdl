#ifndef GDL_MATH_VECTOR4_HPP
#define GDL_MATH_VECTOR4_HPP

#include <cmath>
#include <ostream>

namespace gdl
{
namespace math
{

template<typename T>
class Vector4
{
public:
	T x;
	T y;
	T z;
	T w;
public:
	Vector4();
	Vector4(T x, T y, T z, T w);
	Vector4(const Vector4<T>& rhs);
	Vector4(Vector4<T>&& rhs);
	Vector4<T>& operator=(const Vector4<T>& rhs);
	Vector4<T>& operator=(Vector4<T>&& rhs);
	Vector4<T>& operator+=(const Vector4<T>& rhs);
	Vector4<T>& operator+=(const T rhs);
	Vector4<T>& operator-=(const Vector4<T>& rhs);
	Vector4<T>& operator-=(const T rhs);
	Vector4<T>& operator/=(const Vector4<T>& rhs);
	Vector4<T>& operator/=(const T rhs);
	Vector4<T>& operator*=(const Vector4<T>& rhs);
	Vector4<T>& operator*=(const T rhs);
};

template<typename T>
Vector4<T> operator+(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
Vector4<T> operator+(const Vector4<T>& lhs, const T rhs);

template<typename T>
Vector4<T> operator-(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
Vector4<T> operator-(const Vector4<T>& lhs, const T rhs);

template<typename T>
Vector4<T> operator/(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
Vector4<T> operator/(const Vector4<T>& lhs, const T rhs);

template<typename T>
Vector4<T> operator*(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
Vector4<T> operator*(const Vector4<T>& lhs, const T rhs);

template <typename T>
bool operator==(const Vector4<T>& lhs, const Vector4<T>& rhs);

template <typename T>
bool operator!=(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
T length(const Vector4<T>& v);

template<typename T>
T lengthSquared(const Vector4<T>& v);

template<typename T>
Vector4<T> normal(const Vector4<T>& v);

template<typename T>
T dot(const Vector4<T>& lhs, const Vector4<T>& rhs);

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vector4<T>& v);

#include <gdl/math/Vector4.inl>

typedef Vector4<double> Vector4d;
typedef Vector4<float> Vector4f;
typedef Vector4<int> Vector4i;

}
}

#endif // GDL_MATH_VECTOR4_HPP
