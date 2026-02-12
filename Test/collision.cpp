#include <iostream>
#include <iomanip>
#include "../Core/Include/Body.hpp"
#include "../Core/Include/World.hpp"

int TestCollision()
{

    World physicsWorld;
    physicsWorld.SetGravity(0.0f, 9.81f);

    Body ground(100.0f, 20.0f, 0.0f);
    ground.position = {0.0f, 100.0f};
    ground.restitution = 0.7f;
    physicsWorld.AddBody(&ground);

    Body box(5.0f, 5.0f, 1.0f);
    box.position = {0.0f, 0.0f};
    box.restitution = 0.6f;
    physicsWorld.AddBody(&box);

    float dt = 1.0f / 60.0f;
    std::cout << "Collision Test" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Time\t| Y Position\t| Y Speed\t\t| Condition" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for (int i = 0; i < 500; ++i)
    {
        float currentTime = i * dt;

        float oldVelY = box.velocity.y;

        physicsWorld.Step(dt);

        bool justCollided = (oldVelY > 0 && box.velocity.y < 0);

        if (i % 10 == 0 || justCollided)
        {
            std::cout << currentTime << "s\t| "
                      << box.position.y << "\t| "
                      << box.velocity.y << "\t| "
                      << (justCollided ? "<<< SCRATCHING AND JUMPING! >>>" : "")
                      << std::endl;
        }
    }

    return 0;
}