#include "../Include/body.hpp"

namespace TaqPhysicEngine
{

    void AddForce(Body &b, const Vector2 &f)
    {
        b.force.x += f.x;
        b.force.y += f.y;
    }

    void ClearForces(Body &b)
    {
        b.force = {0, 0};
    }
}