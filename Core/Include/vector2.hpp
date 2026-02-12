#pragma once
#include <cmath>

struct Vector2
{
    float x, y;

    Vector2 operator+(const Vector2 &v) const { return {x + v.x, y + v.y}; }
    Vector2 operator-(const Vector2 &v) const { return {x - v.x, y - v.y}; }

    Vector2 operator*(float s) const { return {x * s, y * s}; }

    Vector2 operator*(const Vector2 &v) const { return {x * v.x, y * v.y}; }

    Vector2 &operator+=(const Vector2 &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }
    Vector2 &operator-=(const Vector2 &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }
    Vector2 &operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    float Dot(const Vector2 &v) const { return x * v.x + y * v.y; }
    float LengthSq() const { return x * x + y * y; }
    float Length() const { return std::sqrt(LengthSq()); }
};

inline Vector2 operator*(float s, const Vector2 &v)
{
    return {v.x * s, v.y * s};
}