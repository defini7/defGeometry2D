# defGeometry2D

## General

A 2D geometry utility library designed for handling various geometric shapes and performing collision detection and intersection tests between them.

> *I've already built a house, raised children. Now I need to plant a geometree!*

## Overview

The library provides:

1) A templated 2D vector (`vec2d<T>`) with arithmetic, vector operations, and utilities.

2) Basic geometric shapes: `circle<T>`, `line<T>`, and axis-aligned rectangles (`rect<T>`).

3) Functions to check containment and intersection between points, lines, circles, and rectangles.

## Namespaces

### def

Main namespace containing all geometry-related classes and functions.

### def::utils

Contains utility functions like approximate equality checks.

## Constants

1) Small tolerance used for floating-point comparison in geometric tests.

```cpp
constexpr double EPSILON = 0.1;
```

2) Mathematical constant π.

```cpp
constexpr double PI = 3.141592653589793;
```

## Templates and Classes

### vec2d<T>

A generic 2D vector supporting arithmetic and vector math. The type `T` must be numeric (`int`, `float`, `double`, etc.).

#### Fields

Coordinates:

```cpp
T x, y;
```

#### Constructors

- Default constructor, initializes `x` and `y` to zero.

```cpp
constexpr vec2d() = default;
```

- Constructs vector with specified `x` and `y`.

```cpp
constexpr vec2d(const T& x, const T& y);
```

- Constructs vector with both `x` and `y` set to `xy`.

```cpp
constexpr vec2d(const T& xy);
```

#### Methods

- Clamps each coordinate between corresponding start and end values.

```cpp
constexpr vec2d<T> clamp(const vec2d<T>& start, const vec2d<T>& end) const;
```

- Linearly interpolates this vector towards vector `v` by fraction `t`.

```cpp
constexpr vec2d<T> lerp(const vec2d<T>& v, const double t) const;
```

- Computes Euclidean distance to vector `v`.

```cpp
constexpr auto dist(const vec2d<T>& v) const;
```

- Returns dot product with vector `v`.

```cpp
constexpr auto dot(const vec2d<T>& v) const;
```

- Returns 2D cross product (scalar) with vector `v`.

```cpp
constexpr auto cross(const vec2d<T>& v) const;
```

- Returns angle (in radians) between this vector and `v`.

```cpp
constexpr auto angle(const vec2d<T>& v) const;
```

- Returns Euclidean length of the vector.

```cpp
constexpr auto length() const;
```

- Alias for length().

```cpp
constexpr auto mag() const;
```

- Returns squared magnitude (length squared).

```cpp
constexpr auto mag2() const;
```

- Manhattan distance to vector `v`.

```cpp
constexpr auto man(const vec2d<T>& v) const;
```

- Component-wise maximum with `v`.

```cpp
constexpr vec2d<T> max(const vec2d<T>& v) const;
```

- Component-wise minimum with `v`.

```cpp
constexpr vec2d<T> min(const vec2d<T>& v) const;
```

- Swaps this vector's components with vector `v`.

```cpp
constexpr void swap(vec2d<T>& v);
```

- Returns normalized (unit length) vector.

```cpp
constexpr vec2d<T> norm() const;
```

- Returns vector with absolute values of components.

```cpp
constexpr vec2d<T> abs() const;
```

- Returns perpendicular vector rotated +90 degrees.

```cpp
constexpr vec2d<T> perp() const;
```

- Applies `floor` to each component.

```cpp
constexpr vec2d<T> floor() const;
```

- Applies `ceil` to each component.

```cpp
constexpr vec2d<T> ceil() const;
```

- Applies `round` to each component.

```cpp
constexpr vec2d<T> round() const;
```

- Converts polar coordinates (angle = y, radius = x) to Cartesian.

```cpp
constexpr vec2d<T> cart() const;
```

- Returns vector in polar form (magnitude, angle).

```cpp
constexpr vec2d<T> polar() const;
```

- Returns string representation in format `"(x, y)"`.

```cpp
std::string str() const;
```

- Converts vector to different numeric type `F`.

```cpp
template <class F>
constexpr operator vec2d<F>() const;
```

---

### circle<T>

Represents a circle with position and radius.

```cpp
template <class T>
struct circle;
```

#### Fields

- Center position.

```cpp
vec2d<T> pos;
```

- Radius.

```cpp
float radius;
```

#### Constructors

- Default constructor.

```cpp
constexpr circle() = default;
```

- Constructs a circle with position and radius.

```cpp
constexpr circle(const vec2d<T>& pos, float radius);
```

#### Methods

- Calculates circle's area.

```cpp
constexpr T area() const;
```

- Calculates circle's circumference.

```cpp
constexpr T circumference() const;
```

---

### line<T>

Represents a line segment between two points.

```cpp
template <class T>
struct line;
```

#### Fields

- Start point.

```cpp
vec2d<T> start;
```

- End point.

```cpp
vec2d<T> end;
```

#### Constructors

- Default constructor.

```cpp
constexpr line() = default;
```

- Constructs line from start to end.

```cpp
constexpr line(const vec2d<T>& start, const vec2d<T>& end);
```

#### Methods

- Returns the vector from start to end.

```cpp
constexpr vec2d<T> vector() const;
```

- Computes distance from a point to this line segment.

```cpp
template <class T1>
constexpr T dist(const vec2d<T1>& v) const;
```

---

### rect<T>

Axis-aligned rectangle represented by position (top-left corner) and size.

```cpp
template <class T>
struct rect;
```

#### Fields

- Top-left corner position.

```cpp
vec2d<T> pos;
```

- Size (width and height).

```cpp
vec2d<T> size;
```

#### Constants

- Number of rectangle sides.

```cpp
static constexpr uint8_t SIDES = 4;
```

#### Constructors

- Default constructor.

```cpp
constexpr rect() = default;
```

- Constructs rectangle with position and size.

```cpp
constexpr rect(const vec2d<T>& pos, const vec2d<T>& size);
```

#### Methods

- Computes area.

```cpp
constexpr T area() const;
```

- Computes perimeter.

```cpp
constexpr T perimeter() const;
```

- Returns left side as a line.

```cpp
constexpr line<T> left() const;
```

- Returns top side as a line.

```cpp
constexpr line<T> top() const;
```

- Returns right side as a line.

```cpp
constexpr line<T> right() const;
```

- Returns bottom side as a line.

```cpp
constexpr line<T> bottom() const;
```

- Returns top-left corner.

```cpp
constexpr vec2d<T> top_left() const;
```

- Returns top-right corner.

```cpp
constexpr vec2d<T> top_right() const;
```

- Returns bottom-left corner.

```cpp
constexpr vec2d<T> bottom_left() const;
```

- Returns bottom-right corner.

```cpp
constexpr vec2d<T> bottom_right() const;
```

- Returns side line by index (0-3).

```cpp
constexpr line<T> side(uint32_t i) const;
```

---

## Enumeration

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

Represents sides of a rectangle and default/invalid side.

---

## Utility Functions

### utils::equal(lhs, rhs)

Approximate equality check for numeric types with tolerance `EPSILON`.

---

## Containment Functions

- `contains(point, point)`: Checks if two points have the same coordinates.
- `contains(circle, point)`: Checks if point lies inside or on a circle.
- `contains(rect, point)`: Checks if point is inside rectangle bounds.
- `contains(rect1, rect2)`: Checks if rectangle1 fully contains rectangle2.
- `contains(rect, line)`: Checks if rectangle entirely contains a line segment.
- `contains(rect, circle)`: Checks if rectangle contains a circle (via circumscribing rectangle).
- `contains(line1, line2)`: Checks if one line contains another line.
- `contains(line, point)`: Checks if point lies on a line segment with tolerance.
- `contains(circle1, circle2)`: Checks if circle1 fully contains circle2.
- `contains(circle, line)`: Checks if circle contains both end points of a line.
- `contains(circle, rect)`: Checks if circle contains all corners of rectangle.

---

## Intersection Functions

Intersection tests exist for all combinations of points, lines, circles, and rectangles.

Examples:

- `intersects(rect1, rect2, intersections, sides)`  
Detects intersection points and sides involved.

- Each function outputs intersection points via a reference `std::vector<vec2d<T>>` and optionally which side(s) were intersected for rectangles.

- Utilizes geometric formulas such as line-line intersection, circle-line intersection, circle-circle intersection, etc.

---
