#pragma once

#include <ostream>

struct Vec2D
{
    float x, y;

    Vec2D();
    Vec2D(float p_x, float p_y);

	void operator+=(const Vec2D &other);
    friend std::ostream &operator<<(std::ostream &os, const Vec2D &vec);
};
