#pragma once
#include "vector2.hpp"

struct Body
{
    Vector2 position = {0, 0};
    Vector2 velocity = {0, 0};
    Vector2 force = {0, 0};

    float width, height;
    float mass, invMass;

    float restitution;
    float friction;

    Body(float w, float h, float m) : width(w), height(h), mass(m)
    {
        invMass = (m > 0.0f) ? 1.0f / m : 0.0f;
        restitution = 0.5f;
        friction = 0.2f;
    }
};
