#ifndef DEF_GEOMETRY2D_HPP
#define DEF_GEOMETRY2D_HPP

#pragma region Documentation
/***
* - Constants
*     - EPSILON - is used for comparing floating point values
*     - PI - is just the Pi number stolen from the Internet (just kidding... I calculated it myself)
* - Functions
*     - utils::equal - checks if difference between 2 values is less than or equals to the EPSILON constant
*                      (values must have *-* and *<=* operators implemented)
* - Structs
*     - vec2d<T> - a struct for storing *x* and *y* components of type T
*         - Methods:
*             - vec2d::clamp - clamps each component to the *start* and *end*
*             - vec2d::lerp - lineally interpolates each component between *start* and *end*
*             - vec2d::dist - calculates distance between *this* and *v* points
*             - vec2d::dot - calculates dot product of *this* and *v* vectors
*             - vec2d::cross - calculates cross product of *this* and *v* vectors
*             - vec2d::angle - calculates angle between *this* and *v* using dot product
*             - vec2d::length - calculates a length of the vector
*             - vec2d::mag - calculates a length of the vector
*             - vec2d::mag2 - calculates a square root out of the vec2d::mag value
*             - vec2d::man - calculates Manhattan distance between *this* and *v* points
*             - vec2d::max - performs std::max function on each component of *this* with the *v* components
*             - vec2d::min - performs std::min function on each component of *this* with the *v* components
*             - vec2d::swap - swaps components of *this* and *v* vectors
*             - vec2d::norm - returns *v* / *v.length()*
*             - vec2d::abs - performs std::abs on each component of the vector
*             - vec2d::perp - returns a perpendicular vector to the *this* vector
*             - vec2d::floor - performs std::floor on each component of the vector
*             - vec2d::ceil - performs std::ceil on each component of the vector
*             - vec2d::round - performs std::round on each component of the vector
*             - vec2d::cart - treats *x* as a radius and *y* as an angle and returns a vector where *x* and *y* are points in the cartesian space
*             - vec2d::polar - returns a vector where "x" component is a length of the *this* vector and "y" is the angle between (length, 0) and (x, y) points
*             - vec2d::str - returns *x* and *y* components as a string: "(x, y)"
***/
#pragma endregion

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdint>

#ifndef DGE_IGNORE_VEC2D
#define DGE_IGNORE_VEC2D
#endif

namespace def
{
	constexpr double EPSILON = 0.1;
	constexpr double PI = 3.141592653589793;

	namespace utils
	{
		template <class T1, class T2>
		constexpr auto equal(T1 lhs, T2 rhs);
	}

	template <class T>
	struct vec2d
	{
		static_assert(std::is_arithmetic<T>::value, "vec2d<T> must be numeric");

		constexpr vec2d() = default;
		constexpr vec2d(const T& x, const T& y);

		constexpr vec2d(const vec2d&) = default;
		constexpr vec2d& operator=(const vec2d&) = default;

		T x = 0, y = 0;

		constexpr vec2d clamp(const vec2d& start, const vec2d& end) const;
		constexpr vec2d lerp(const vec2d& v, const double t) const;
		constexpr auto dist(const vec2d& v) const;

		constexpr auto dot(const vec2d& v) const;
		constexpr auto cross(const vec2d& v) const;

		constexpr auto angle(const vec2d& v) const;
		constexpr auto length() const;

		constexpr auto mag() const;
		constexpr auto mag2() const;

		constexpr auto man(const vec2d& v) const;

		constexpr vec2d max(const vec2d& v) const;
		constexpr vec2d min(const vec2d& v) const;

		constexpr void swap(vec2d& v);

		constexpr vec2d norm() const;
		constexpr vec2d abs() const;
		constexpr vec2d perp() const;
		constexpr vec2d floor() const;
		constexpr vec2d ceil() const;
		constexpr vec2d round() const;
		constexpr vec2d cart() const;
		constexpr vec2d polar() const;

		std::string str() const;

		template <class F>
		constexpr operator vec2d<F>() const
		{
			return { static_cast<F>(this->x), static_cast<F>(this->y) };
		}
	};

	typedef vec2d<int> vi2d;
	typedef vec2d<float> vf2d;
	typedef vec2d<double> vd2d;

	template <class T1, class T2>
	constexpr vec2d<T1>& operator+=(vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator-=(vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator*=(vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator/=(vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator%=(vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator+=(vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator-=(vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator*=(vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator/=(vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<T1>& operator%=(vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator%(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const vec2d<T1>& v1, const T2& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const T1& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const T1& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const T1& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const T1& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator%(const T1& v1, const vec2d<T2>& v2);

	template <class T>
	constexpr vec2d<T> operator-(const vec2d<T>& v);

	template <class T1, class T2>
	constexpr bool operator==(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr bool operator<=(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr bool operator>=(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr bool operator<(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr bool operator>(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T1, class T2>
	constexpr bool operator!=(const vec2d<T1>& v1, const vec2d<T2>& v2);

	template <class T>
	struct circle
	{
		constexpr circle() = default;
		constexpr circle(const vec2d<T>& pos, float radius);

		constexpr T area() const;
		constexpr T circumference() const;

		vec2d<T> pos;
		float radius = 0.0f;
	};

	template <class T>
	struct line
	{
		constexpr line() = default;
		constexpr line(const vec2d<T>& start, const vec2d<T>& end);

		constexpr vec2d<T> vector() const;

		template <class T1>
		constexpr T dist(const vec2d<T1>& v) const;

		vec2d<T> start, end;
	};

	enum side : uint8_t
	{
		SIDE_LEFT,
		SIDE_TOP,
		SIDE_RIGHT,
		SIDE_BOTTOM,
		SIDE_NONE
	};

	template <class T>
	struct rect
	{
		constexpr rect() = default;
		constexpr rect(const vec2d<T>& pos, const vec2d<T>& size);

		constexpr T area() const;
		constexpr T perimeter() const;

		constexpr line<T> left() const;
		constexpr line<T> top() const;
		constexpr line<T> right() const;
		constexpr line<T> bottom() const;

		constexpr vec2d<T> top_left() const;
		constexpr vec2d<T> top_right() const;
		constexpr vec2d<T> bottom_left() const;
		constexpr vec2d<T> bottom_right() const;

		constexpr line<T> side(uint32_t i) const;

		vec2d<T> pos;
		vec2d<T> size;

		static constexpr uint8_t SIDES = 4;
	};

	// point contains point
	// rectangle contains point
	// rectangle contains rectangle
	// rectangle contains line
	// rectangle contains circle
	// line contains point
	// line contains line
	// circle contains point
	// circle contains circle
	// circle contains line
	// circle contains rectangle
	// point intersects point
	// point intersects circle
	// point intersects rectangle
	// point intersects line
	// rectangle intersects point
	// rectangle intersects line
	// rectangle intersects rectangle
	// rectangle intersects circle
	// line intersects point
	// line intersects line
	// line intersects rectangle
	// line intersects circle
	// circle intersects point
	// circle intersects line
	// circle intersects rectangle
	// circle intersects circle

	// Checks if p1 and p2 have the same coordinates
	template <class T1, class T2>
	constexpr bool contains(const vec2d<T1>& p1, const vec2d<T2>& p2);

	// Checks if r contains p
	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const vec2d<T2>& p);

	// Checks if r1 contains r2
	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r1, const rect<T2>& r2);

	// Checks if r contains l
	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const line<T2>& l);

	// Checks if r contains с
	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const circle<T2>& c);

	// Checks if l1 contains l2
	template <class T1, class T2>
	constexpr bool contains(const line<T1>& l1, const line<T2>& l2);

	// Checks if l contains p
	template <class T1, class T2>
	constexpr bool contains(const line<T1>& l, const vec2d<T2>& p);

	// Checks if c contains p
	template <class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const vec2d<T2>& p);

	// Checks if c contains l
	template <class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const line<T2>& l);

	// Checks if c contains r
	template <class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const rect<T2>& r);

	// Checks if c1 contains c2
	template <class T1, class T2>
	constexpr bool contains(const circle<T1>& c1, const circle<T2>& c2);

	// Checks if p1 and p2 have the same coordinates
	template <class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p1, const vec2d<T2>& p2, std::vector<vec2d<T2>>& intersections);

	// Checks if p intersects l
	template <class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const line<T2>& l, std::vector<vec2d<T2>>& intersections);

	// Checks if p intersects r
	template <class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, side* s = nullptr);

	// Checks if p intersects circle
	template <class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const circle<T2>& c, std::vector<vec2d<T2>>& intersections);

	// Checks if c intersects p
	template <class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections);

	// Checks if r intersects p
	template <class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections, side* s = nullptr);

	// Checks if r1 intersects r2
	template <class T1, class T2>
	constexpr bool intersects(const rect<T1>& r1, const rect<T2>& r2, std::vector<vec2d<T2>>& intersections, std::vector<side>* s = nullptr);

	// Checks if r intersects c
	template <class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const circle<T2>& c, std::vector<vec2d<T2>>& intersections, std::vector<side>* s = nullptr);

	// Checks if l1 intersects l2
	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l1, const line<T2>& l2, std::vector<vec2d<T2>>& intersections);

	// Checks if l intersects r
	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, std::vector<side>* s = nullptr);

	// Checks if l intersects c
	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const circle<T2>& c, std::vector<vec2d<T2>>& intersections);

	// Checks if r intersects l
	template <class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const line<T2>& l, std::vector<vec2d<T2>>& intersections, std::vector<side>* s = nullptr);

	// Checks if l intersects p
	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections);

	// Checks if c1 intersects c2
	template <class T1, class T2>
	constexpr bool intersects(const circle<T1>& c1, const circle<T2>& c2, std::vector<vec2d<T2>>& intersections);

	// Checks if c intersects l
	template <class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const line<T2>& l, std::vector<vec2d<T2>>& intersections);

	// Checks if c intersects r
	template <class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, std::vector<side>* s = nullptr);

#define DEF_GEOMETRY2D_IMPL

#ifdef DEF_GEOMETRY2D_IMPL
#undef DEF_GEOMETRY2D_IMPL

	template <class T>
	constexpr vec2d<T>::vec2d(const T& x, const T& y) : x(x), y(y)
	{

	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator+=(vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator-=(vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator*=(vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		v1.x *= v2.x;
		v1.y *= v2.y;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator/=(vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		v1.x /= v2.x;
		v1.y /= v2.y;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator%=(vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		v1.x %= v2.x;
		v1.y %= v2.y;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator+=(vec2d<T1>& v1, const T2& v2)
	{
		v1.x += v2;
		v1.y += v2;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator-=(vec2d<T1>& v1, const T2& v2)
	{
		v1.x -= v2;
		v1.y -= v2;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator*=(vec2d<T1>& v1, const T2& v2)
	{
		v1.x *= v2;
		v1.y *= v2;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator/=(vec2d<T1>& v1, const T2& v2)
	{
		v1.x /= v2;
		v1.y /= v2;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<T1>& operator%=(vec2d<T1>& v1, const T2& v2)
	{
		v1.x %= v2;
		v1.y %= v2;
		return v1;
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1.x + v2.x, v1.y + v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1.x - v2.x, v1.y - v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1.x * v2.x, v1.y * v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1.x / v2.x, v1.y / v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator%(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1.x % v2.x, v1.y % v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const vec2d<T1>& v1, const T2& v2)
	{
		return vec2d(v1.x + v2, v1.y + v2);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const vec2d<T1>& v1, const T2& v2)
	{
		return vec2d(v1.x - v2, v1.y - v2);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const vec2d<T1>& v1, const T2& v2)
	{
		return vec2d(v1.x * v2, v1.y * v2);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const vec2d<T1>& v1, const T2& v2)
	{
		return vec2d(v1.x / v2, v1.y / v2);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator+(const T1& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1 + v2.x, v1 + v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator-(const T1& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1 - v2.x, v1 - v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator*(const T1& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1 * v2.x, v1 * v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator/(const T1& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1 / v2.x, v1 / v2.y);
	}

	template <class T1, class T2>
	constexpr vec2d<decltype(T1(1) + T2(1))> operator%(const T1& v1, const vec2d<T2>& v2)
	{
		return vec2d(v1 % v2.x, v1 % v2.y);
	}

	template <class T>
	constexpr vec2d<T> operator-(const vec2d<T>& v)
	{
		return vec2d(-v.x, -v.y);
	}

	template <class T1, class T2>
	constexpr bool operator==(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x == v2.x && v1.y == v2.y;
	}

	template <class T1, class T2>
	constexpr bool operator<=(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x <= v2.x && v1.y <= v2.y;
	}

	template <class T1, class T2>
	constexpr bool operator>=(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x >= v2.x && v1.y >= v2.y;
	}

	template <class T1, class T2>
	constexpr bool operator<(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x < v2.x && v1.y < v2.y;
	}

	template <class T1, class T2>
	constexpr bool operator>(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x > v2.x && v1.y > v2.y;
	}

	template <class T1, class T2>
	constexpr bool operator!=(const vec2d<T1>& v1, const vec2d<T2>& v2)
	{
		return v1.x != v2.x || v1.y != v2.y;
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::clamp(const vec2d& start, const vec2d& end) const
	{
		return { std::clamp(x, start.x, end.x), std::clamp(y, start.y, end.y) };
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::lerp(const vec2d& v, const double t) const
	{
		return { (T)std::lerp(x, v.x, t), (T)std::lerp(y, v.y, t) };
	}

	template <class T>
	constexpr auto vec2d<T>::dist(const vec2d<T>& v) const
	{
		return (*this - v).length();
	}

	template <class T>
	constexpr auto vec2d<T>::dot(const vec2d& v) const
	{
		return x * v.x + y * v.y;
	}

	template <class T>
	constexpr auto vec2d<T>::cross(const vec2d& v) const
	{
		return x * v.y - y * v.x;
	}

	template<typename T>
	constexpr auto vec2d<T>::angle(const vec2d& v) const
	{
		return acos(dot(v) / (length() + v.length()));
	}

	template <class T>
	constexpr auto vec2d<T>::length() const
	{
		return mag();
	}

	template <class T>
	constexpr auto vec2d<T>::mag() const
	{
		return static_cast<T>(std::sqrt(x * x + y * y));
	}

	template <class T>
	constexpr auto vec2d<T>::mag2() const
	{
		return static_cast<T>(x * x + y * y);
	}

	template <class T>
	constexpr auto vec2d<T>::man(const vec2d& v) const
	{
		return std::abs(x - v.x) + std::abs(y - v.y);
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::max(const vec2d& v) const
	{
		return vec2d(std::max(x, v.x), std::max(y, v.y));
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::min(const vec2d& v) const
	{
		return vec2d(std::min(x, v.x), std::min(y, v.y));
	}

	template <class T>
	constexpr void vec2d<T>::swap(vec2d& v)
	{
		std::swap(x, v.x);
		std::swap(y, v.y);
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::norm() const
	{
		auto n = (T)1 / mag();
		return vec2d(x * n, y * n);
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::abs() const
	{
		return vec2d(std::abs(x), std::abs(y));
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::perp() const
	{
		return vec2d(-y, x);
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::floor() const
	{
		return vec2d(std::floor(x), std::floor(y));
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::ceil() const
	{
		return vec2d(std::ceil(x), std::ceil(y));
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::round() const
	{
		return vec2d(std::round(x), std::round(y));
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::cart() const
	{
		return vec2d(cos(y) * x, sin(y) * x);
	}

	template <class T>
	constexpr vec2d<T> vec2d<T>::polar() const
	{
		return vec2d(mag(), atan2(y, x));
	}

	template <class T>
	std::string vec2d<T>::str() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	template <class T1, class T2>
	constexpr auto utils::equal(T1 lhs, T2 rhs)
	{
		return abs(lhs - rhs) <= EPSILON;
	}

	template <class T>
	constexpr rect<T>::rect(const vec2d<T>& p, const vec2d<T>& s)
	{
		pos = p;
		size = s;
	}

	template <class T>
	constexpr T rect<T>::area() const
	{
		return size.x * size.y;
	}

	template <class T>
	constexpr T rect<T>::perimeter() const
	{
		return 2 * (size.x + size.y);
	}

	template <class T>
	constexpr line<T> rect<T>::left() const
	{
		return { pos, { pos.x, pos.y + size.y } };
	}

	template <class T>
	constexpr line<T> rect<T>::top() const
	{
		return { pos, { pos.x + size.x, pos.y } };
	}

	template <class T>
	constexpr line<T> rect<T>::right() const
	{
		return { { pos.x + size.x, pos.y }, bottom_right() };
	}

	template <class T>
	constexpr line<T> rect<T>::bottom() const
	{
		return { { pos.x, pos.y + size.y }, bottom_right() };
	}

	template<class T>
	constexpr vec2d<T> rect<T>::top_left() const
	{
		return pos;
	}

	template<class T>
	constexpr vec2d<T> rect<T>::top_right() const
	{
		return { pos.x + size.x, pos.y };
	}

	template<class T>
	constexpr vec2d<T> rect<T>::bottom_left() const
	{
		return { pos.x, pos.y + size.y };;
	}

	template<class T>
	constexpr vec2d<T> rect<T>::bottom_right() const
	{
		return pos + size;
	}

	template<class T>
	constexpr line<T> rect<T>::side(uint32_t i) const
	{
		switch (i)
		{
		case SIDE_LEFT: return left();
		case SIDE_TOP: return top();
		case SIDE_RIGHT: return right();
		case SIDE_BOTTOM: return bottom();
		}

		return {};
	}

	template <class T>
	constexpr circle<T>::circle(const vec2d<T>& p, float r)
	{
		pos = p;
		radius = r;
	}

	template <class T>
	constexpr T circle<T>::area() const
	{
		return PI * double(radius * radius);
	}

	template <class T>
	constexpr T circle<T>::circumference() const
	{
		return 2.0 * PI * (double)radius;
	}

	template <class T>
	constexpr line<T>::line(const vec2d<T>& s, const vec2d<T>& e)
	{
		start = s;
		end = e;
	}

	template <class T>
	constexpr vec2d<T> line<T>::vector() const
	{
		return end - start;
	}

	template <class T1, class T2>
	constexpr bool contains(const vec2d<T1>& p1, const vec2d<T2>& p2)
	{
		return utils::equal(p1.x, p2.x) && utils::equal(p1.y, p2.y);
	}

	template <class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const vec2d<T2>& p)
	{
		auto sqr_radius = c.radius * c.radius;
		auto sqr_dist = (c.pos - p).mag2();

		return sqr_dist < sqr_radius || utils::equal(sqr_dist, sqr_radius);
	}

	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const vec2d<T2>& p)
	{
		return p >= r.pos && p <= r.bottom_right();
	}

	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r1, const rect<T2>& r2)
	{
		return r1.pos <= r2.pos && r1.bottom_right() >= r2.bottom_right();
	}

	template <class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const line<T2>& l)
	{
		return l.start >= r.pos && l.end >= r.pos && l.start <= r.bottom_right() && l.end <= r.bottom_right();
	}

	template<class T1, class T2>
	constexpr bool contains(const rect<T1>& r, const circle<T2>& c)
	{
		rect<T2> rect_circle(c.pos - c.radius, vec2d<T2>(c.radius * 2));
		return contains(r, rect_circle);
	}

	template <class T1, class T2>
	constexpr bool contains(const line<T1>& l1, const line<T2>& l2)
	{
		return (contains(l1.start, l2.start) && contains(l1.end, l2.end)) || (contains(l1.start, l2.end) && contains(l1.end, l2.start));
	}

	template<class T1, class T2>
	constexpr bool contains(const line<T1>& l, const vec2d<T2>& p)
	{
		vec2d<T1> vec = l.vector();

		auto dp = vec.dot(p - l.start) / vec.mag2();

		if (dp < 0 || dp > 1)
			return false;

		vec2d<T2> proj = l.start.lerp(l.end, dp);

		// We need to find a proper epsilon value
		return p.dist(proj) < EPSILON;
	}

	template<class T1, class T2>
	constexpr bool contains(const circle<T1>& c1, const circle<T2>& c2)
	{
		return c1.radius >= c1.pos.dist(c2.pos) + c2.radius;
	}

	template<class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const line<T2>& l)
	{
		return contains(c, l.start) && contains(c, l.end);
	}

	template<class T1, class T2>
	constexpr bool contains(const circle<T1>& c, const rect<T2>& r)
	{
		auto radius2 = c.radius * c.radius;

		auto check_dist = [&](const vec2d<T2>& edge)
			{
				const auto diff = edge - c.pos;
				return diff.dot(diff) <= radius2;
			};

		return check_dist(r.pos) && check_dist(r.top_right()) && check_dist(r.bottom_left()) && check_dist(r.bottom_right());
	}

	template<class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p1, const vec2d<T2>& p2, std::vector<vec2d<T2>>& intersections)
	{
		if (contains(p1, p2))
		{
			intersections.push_back(p2);
			return true;
		}

		return false;
	}

	template<class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const line<T2>& l, std::vector<vec2d<T2>>& intersections)
	{
		return intersects(l, p, intersections);
	}

	template<class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, side* s)
	{
		return intersects(r, p, intersections, s);
	}

	template<class T1, class T2>
	constexpr bool intersects(const vec2d<T1>& p, const circle<T2>& c, std::vector<vec2d<T2>>& intersections)
	{
		return intersects(c, p, intersections);
	}

	template<class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections)
	{
		if (utils::equal((c.pos - p).mag2(), c.radius * c.radius))
		{
			intersections.push_back(p);
			return true;
		}

		return false;
	}

	template<class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections, side* s)
	{
		for (uint8_t i = 0; i < r.SIDES; i++)
		{
			if (contains(r.side(i), p))
			{
				if (s) *s = i;
				intersections.push_back(p);
				return true;
			}
		}

		return false;
	}

	template<class T1, class T2>
	constexpr bool intersects(const rect<T1>& r1, const rect<T2>& r2, std::vector<vec2d<T2>>& intersections, std::vector<side>* s)
	{
		intersections.clear();

		for (uint8_t i = 0; i < r1.SIDES; i++)
		{
			line<T1> side = r1.side(i);
			bool intersected = false;

			for (uint8_t j = 0; j < r2.SIDES; j++)
			{
				std::vector<vec2d<T2>> points;
				intersects(side, r2.side(j), points);

				if (!points.empty())
				{
					intersections.push_back(points[0]);
					intersected = true;
				}
			}

			if (intersected)
				if (s) s->push_back(def::side(i));
		}

		return !intersections.empty();
	}

	template<class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const circle<T2>& c, std::vector<vec2d<T2>>& intersections, std::vector<side>* s)
	{
		return intersects(c, r, intersections, s);
	}

	template<class T1, class T2>
	constexpr bool intersects(const line<T1>& l1, const line<T2>& l2, std::vector<vec2d<T2>>& intersections)
	{
		// l1: a1 * x + b1 * y = -c1
		// l2: a2 * x + b2 * y = -c2

		const auto a1 = l1.start.y - l1.end.y;
		const auto b1 = l1.end.x - l1.start.x;

		const auto a2 = l2.start.y - l2.end.y;
		const auto b2 = l2.end.x - l2.start.x;

		const auto det = a1 * b2 - b1 * a2;

		if (det == 0)
		{
			// Determinant is 0 so the lines are collinear

			// one line is inside another line so there are infinite
			// number of solutions or no solutions at all
			return contains(l2, l1.start) || contains(l1, l2.start);
		}

		const auto c1 = l1.start.x * l1.end.y - l1.end.x * l1.start.y;
		const auto c2 = l2.start.x * l2.end.y - l2.end.x * l2.start.y;

		const vec2d<T2> point = { (b1 * c2 - b2 * c1) / det, (a2 * c1 - a1 * c2) / det };

		if (contains(l1, point) && contains(l2, point))
		{
			intersections.resize(1);
			intersections[0] = point;
			return true;
		}

		return false;
	}

	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, std::vector<side>* s)
	{
		return intersects(r, l, intersections, s);
	}

	template <class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const circle<T2>& c, std::vector<vec2d<T2>>& intersections)
	{
		return intersects(c, l, intersections);
	}

	template<class T1, class T2>
	constexpr bool intersects(const rect<T1>& r, const line<T2>& l, std::vector<vec2d<T2>>& intersections, std::vector<side>* s)
	{
		intersections.clear();

		for (uint8_t i = 0; i < r.SIDES; i++)
		{
			std::vector<vec2d<T1>> points;
			intersects(l, r.side(i), points);

			if (!points.empty())
			{
				if (s) s->push_back(i);
				intersections.push_back(points[0]);
			}
		}

		return !intersections.empty();
	}

	template<class T1, class T2>
	constexpr bool intersects(const line<T1>& l, const vec2d<T2>& p, std::vector<vec2d<T2>>& intersections)
	{
		if (contains(l, p))
		{
			intersections.push_back(p);
			return true;
		}

		return false;
	}

	template<class T1, class T2>
	constexpr bool intersects(const circle<T1>& c1, const circle<T2>& c2, std::vector<vec2d<T2>>& intersections)
	{
		intersections.clear();

		const auto sqr_r1 = c1.radius * c1.radius;
		const auto sqr_r2 = c2.radius * c2.radius;

		const auto dist = c1.pos.dist(c2.pos);
		const auto adj = (sqr_r1 - sqr_r2 + dist * dist) / (2 * dist);
		const auto sqr_hyp = sqr_r1 - adj * adj;

		if (sqr_hyp < 0)
			return false;

		const auto hyp = sqrt(sqr_hyp);

		vec2d<T2> p = (c2.pos - c1.pos) * (adj / dist) + c1.pos;
		vec2d<T2> inter1, inter2;

		inter1.x = p.x + hyp * (c2.pos.y - c1.pos.y) / dist;
		inter1.y = p.y - hyp * (c2.pos.x - c1.pos.x) / dist;

		inter2.x = p.x - hyp * (c2.pos.y - c1.pos.y) / dist;
		inter2.y = p.y + hyp * (c2.pos.x - c1.pos.x) / dist;

		intersections.push_back(inter1);

		if (!utils::equal(inter1, inter2))
			intersections.push_back(inter2);

		return true;
	}

	template<class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const line<T2>& l, std::vector<vec2d<T2>>& intersections)
	{
		intersections.clear();

		const auto dist = l.dist(c.pos);

		if (utils::equal(dist, c.radius))
		{
			// No intersection at all
			return false;
		}

		// Compute point closest to the circle on the line
		const auto d = l.vector();
		const auto uLine = d.dot(c.pos - l.start) / d.mag2();
		const auto closestPointToLine = l.start + uLine * d;
		const auto distToLine = (c.pos - closestPointToLine).mag2();

		if (utils::equal(distToLine, c.radius * c.radius))
		{
			// Only one intersection point
			intersections.push_back(closestPointToLine);
			return true;
		}

		// Circle intersects the line
		const auto length = sqrt(c.radius * c.radius - distToLine);
		const auto p1 = closestPointToLine + d.norm() * length;
		const auto p2 = closestPointToLine - d.norm() * length;

		if (contains(l, p1)) intersections.push_back(p1);
		if (contains(l, p2)) intersections.push_back(p2);

		return !intersections.empty();
	}

	template<class T1, class T2>
	constexpr bool intersects(const circle<T1>& c, const rect<T2>& r, std::vector<vec2d<T2>>& intersections, std::vector<side>* s)
	{
		intersections.clear();

		for (uint8_t i = 0; i < r.SIDES; i++)
		{
			for (const auto& p : intersects(c, r.side(i)))
			{
				if (s) s->push_back(i);
				intersections.push_back(p);
			}
		}

		return !intersections.empty();
	}

	template<class T>
	template<class T1>
	constexpr T line<T>::dist(const vec2d<T1>& v) const
	{
		auto a = end.y - start.y;
		auto b = start.x - end.x;

		if (a == 0 && b == 0)
			return v.dist(start);

		auto c = end.x * start.y - start.x * end.y;

		return abs(a * v.x + b * v.y + c) / sqrt(a * a + b * b);
	}

#endif
}

#endif
