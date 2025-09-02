# Primitives

All geometric primitives are represented as structures:

1) Point
```cpp
template <class T>
struct vec2d;
```

You can construct a point (or a vector) using **x** and **y** values or using only one value that sets both.
```cpp
constexpr vec2d() = default;
constexpr vec2d(const T& x, const T& y);
constexpr vec2d(const T& xy);
```

Performs componentwise std::clamp on **x** and **y**.
```cpp
constexpr vec2d clamp(const vec2d& start, const vec2d& end) const;
```

Performs componentwise std::lerp on **x** and **y** where **this** is a starting point and **v** is the end point.
```cpp
constexpr vec2d lerp(const vec2d& v, const double t) const;
```

Computes distance between 
```cpp
constexpr auto dist(const vec2d& v) const;
```

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

2) Circle
```cpp
template <class T>
struct circle;
```
3) Line
```cpp
template <class T>
struct line;
```
4) Rectangle
```cpp
template <class T>
struct rect;
```

Rectangle also consists of 4 sides:
```cpp
enum side : uint8_t
{
    SIDE_LEFT,
    SIDE_TOP,
    SIDE_RIGHT,
    SIDE_BOTTOM,
    SIDE_NONE
};
```
