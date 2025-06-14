#include "vector.hpp"
#include <ostream>

Vec2D::Vec2D() : x(0), y(0) {}
Vec2D::Vec2D(float p_x, float p_y) : x(p_x), y(p_y) {}

void Vec2D::operator+=(const Vec2D &other)
{
	x += other.x;
	y += other.y;
}

std::ostream &operator<<(std::ostream &os, const Vec2D &vec)
{
	os << "Vec2D(" << vec.x << ", " << vec.y << ")";
	return os;
}
