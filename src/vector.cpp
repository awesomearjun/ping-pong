#include "vector.hpp"

Vec2D::Vec2D() : x(0), y(0) {}
Vec2D::Vec2D(int p_x, int p_y) : x(p_x), y(p_y) {}

Vec2D Vec2D::operator*(const Vec2D &vec2) const
{
    return Vec2D(x * vec2.x, y * vec2.y);
}

void Vec2D::operator+=(const Vec2D &other)
{
	x += other.x;
	y += other.y;
}

Vec2D Vec2D::operator*(int &other)
{
	return Vec2D(x * other, y * other);
}
