#include <iostream>
#include <vector>
#include <iomanip>
#include "../Core/Include/Body.hpp"
#include "../Core/Include/World.hpp"

int TestMultiCollision()
{
    World physicsWorld;
    physicsWorld.SetGravity(0.0f, 9.81f);

    Body ground(200.0f, 20.0f, 0.0f);
    ground.position = {0.0f, 100.0f};
    ground.restitution = 0.5f;
    physicsWorld.AddBody(&ground);

    std::vector<Body *> boxes;
    for (int i = 0; i < 5; ++i)
    {
        Body *b = new Body(5.0f, 5.0f, 1.0f);
        b->position = {(float)(i * 4), (float)(i * -10)};
        b->restitution = 0.5f;
        physicsWorld.AddBody(b);
        boxes.push_back(b);
    }

    float dt = 1.0f / 60.0f;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "        Multiple Collision Test" << std::endl;
    std::cout << "Zaman\t| Kutu 0 Y\t| Kutu 4 Y\t| Durum" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    for (int i = 0; i < 600; ++i)
    { // 10 saniye simülasyon
        physicsWorld.Step(dt);

        if (i % 20 == 0)
        {
            std::cout << i * dt << "s\t| "
                      << boxes[0]->position.y << "\t| "
                      << boxes[4]->position.y << "\t| "
                      << (boxes[0]->position.y > 80 ? "Zeminde Yigiliyorlar" : "Dusus Devam")
                      << std::endl;
        }
    }

    for (auto b : boxes)
        delete b;

    return 0;
}