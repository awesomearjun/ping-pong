//
//  Math.hpp
//  ping-pong
//
//  Created by OnionLord on 2025-02-17.
//

#pragma once

#include <iostream>

struct Vector2f {
    float x, y;

    Vector2f()
    :x(0.0f), y(0.0f)
    {}

    Vector2f(float p_x, float p_y)
    :x(p_x), y(p_y)
    {}

    Vector2f operator*(const Vector2f &p_other) const {
        return Vector2f(x * p_other.x, y * p_other.y);
    }

    Vector2f operator*(const int p_other) const {
        return Vector2f(x * p_other, y * p_other);
    }

    Vector2f operator+(const Vector2f &p_other) const {
        return Vector2f(x + p_other.x, y + p_other.y);
    }

    void operator+=(const Vector2f &p_other) {
        x += p_other.x;
        y += p_other.y;
    }

    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};
