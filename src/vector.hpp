#pragma once

#include <ostream>

struct Vec2D
{
    int x, y;

    Vec2D();
    Vec2D(int p_x, int p_y);

	Vec2D operator*(const Vec2D &vec2) const;
    void operator+=(const Vec2D &other);
    Vec2D operator*(int &other);
	friend std::ostream &operator<<(std::ostream &os, const Vec2D &vec);
};
