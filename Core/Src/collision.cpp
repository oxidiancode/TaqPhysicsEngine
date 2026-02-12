#include "../Include/collision.hpp"
#include <algorithm>

Hit CheckAABB(const Body &a, const Body &b)
{
    // Distance between centres
    Hit hit = {false, 0.0f, {0, 0}};

    // On the X-axis
    float dx = b.position.x - a.position.x;
    float px = (a.width / 2.0f + b.width / 2.0f) - std::abs(dx);
    if (px <= 0)
        return hit;

    // On the Y-axis
    float dy = b.position.y - a.position.y;
    float py = (a.height / 2.0f + b.height / 2.0f) - std::abs(dy);
    if (py <= 0)
        return hit;

    // The axis with less indentation is normal.
    if (px < py)
    {
        hit.collided = true;
        hit.depth = px;
        hit.normal = {0, (dx > 0) ? 1.0f : -1.0f};
    }
    else
    {
        hit.collided = true;
        hit.depth = py;
        hit.normal = {0, (dy > 0) ? 1.0f : -1.0f};
    }
    return hit;
}