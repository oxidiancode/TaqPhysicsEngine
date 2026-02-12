#include <iostream>
#include <iomanip>
#include "../Core/Include/world.hpp"

int TestJump()
{

    World physicsWorld;
    physicsWorld.SetGravity(0.0f, 9.81f);

    Body ground(100.0f, 10.0f, 0.0f);
    ground.position = {0.0f, 50.0f};
    ground.restitution = 0.8f;
    physicsWorld.AddBody(&ground);

    Body box(2.0f, 2.0f, 1.0f);
    box.position = {0.0f, 0.0f};
    box.restitution = 0.5f;
    physicsWorld.AddBody(&box);

    float dt = 1.0f / 60.0f;
    std::cout << "            JUMP TEST" << std::endl;
    std::cout << "Time | Y Position | Speed" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    for (int i = 0; i < 120; ++i)
    {
        physicsWorld.Step(dt);

        if (i % 5 == 0)
        {
            std::cout << std::fixed << std::setprecision(2)
                      << i * dt << "s  |  "
                      << box.position.y << "  |  "
                      << box.velocity.y << std::endl;
        }
    }

    return 0;
}