#pragma once
#include "body.hpp"
struct Hit
{
    bool collided;
    float depth;
    Vector2 normal;
};

Hit CheckAABB(const Body &a, const Body &b);