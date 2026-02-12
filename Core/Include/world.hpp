#pragma once
#include <vector>
#include "body.hpp"
#include "collision.hpp"

class World
{
public:
    std::vector<Body *> bodies;
    World() = default;
    ~World() = default;
    Vector2 gravity = {0.0f, 9.81f};

    void SetGravity(float x, float y) { gravity = {x, y}; }

    void AddBody(Body *b) { bodies.push_back(b); }

    void Step(float dt);

private:
    void ResolveCollision(Body &a, Body &b, const Hit &hit);
    void PositionalCorrection(Body &a, Body &b, const Hit hit);
};