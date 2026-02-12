#include "../Include/world.hpp"
#include <math.h>

void World::Step(float dt)
{
    // Integration (Force and motion)
    for (auto b : bodies)
    {
        // Pass the static objects.
        if (b->invMass == 0.0f)
            continue;

        // Add gravity and external forces to the speed.
        // v = v + a * dt
        b->velocity += gravity * dt;
        b->velocity += (b->force * b->invMass) * dt;

        // Add speed to the location.
        // p = p + v * dt
        b->position += b->velocity * dt;

        // Reset the force for each frame to zero.
        b->force = {0.0f, 0.0f};
    }

    // COLLISION DETECTION & RESOLUTION
    for (size_t i = 0; i < bodies.size(); ++i)
    {
        for (size_t j = i + 1; j < bodies.size(); ++j)
        {
            Body *a = bodies[i];
            Body *b = bodies[j];

            if (a->invMass == 0.0f && b->invMass == 0.0f)
                continue;
            Hit hit = CheckAABB(*a, *b);

            if (hit.collided)
            {
                ResolveCollision(*a, *b, hit);
            }
        }
    }
}

void World::ResolveCollision(Body &a, Body &b, const Hit &hit)
{
    Vector2 rv = b.velocity - a.velocity;
    float velAlongNormal = rv.Dot(hit.normal);

    if (velAlongNormal > 0)
        return;

    float e = std::min(a.restitution, b.restitution);

    float invMassSum = a.invMass + b.invMass;
    if (invMassSum == 0)
        return;

    float j = -(1.0f + e) * velAlongNormal;
    j /= invMassSum;

    Vector2 impulse = hit.normal * j;

    a.velocity -= impulse * a.invMass;
    b.velocity += impulse * b.invMass;

    PositionalCorrection(a, b, hit);
}
void World::PositionalCorrection(Body &a, Body &b, const Hit hit)
{
    const float percent = 0.2f;
    const float slop = 0.01f;

    Vector2 correction = hit.normal * (std::max(hit.depth - slop, 0.0f) / (a.invMass + b.invMass) * percent);
    a.position -= correction * a.invMass;
    b.position += correction * b.invMass;
}