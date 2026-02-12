## 🚀 Installation & Getting Started

### 1. Download the Library
To use **TaqPhysicsEngine** in your project, you need the compiled static library. You can download it directly using the button below:

[![Download libTaqPhysics.a](https://img.shields.io/badge/Download-libTaqPhysics.a-blue?style=for-the-badge&logo=git)](## 🚀 Installation & Getting Started

> **Manual Path:** `Lib/libTaqPhysics.a`

### 2. Basic Usage Example
After adding the library and headers to your project, you can initialize the world and start adding bodies like this:

```cpp
#include "world.hpp"
#include <iostream>

using namespace TaqPhysicEngine;

int main() {
    // 1. Initialize the Physics World
    World world;
    world.SetGravity(0.0f, 9.81f); // Set standard Earth gravity

    // 2. Create a Dynamic Body (width, height, mass)
    Body* box = new Body(2.0f, 2.0f, 1.0f);
    box->position = { 0.0f, -10.0f }; // Start in the air
    
    // 3. Add to the World
    world.AddBody(box);

    // 4. Simulation Loop
    float dt = 1.0f / 60.0f;
    for (int i = 0; i < 60; ++i) {
        world.Step(dt);
        std::cout << "Box Y Position: " << box->position.y << std::endl;
    }

    return 0;
})

> **Manual Path:** `Lib/libTaqPhysics.a`

### 2. Basic Usage Example
After adding the library and headers to your project, you can initialize the world and start adding bodies like this:

```cpp
#include "world.hpp"
#include <iostream>

using namespace TaqPhysicEngine;

int main() {
    // 1. Initialize the Physics World
    World world;
    world.SetGravity(0.0f, 9.81f); // Set standard Earth gravity

    // 2. Create a Dynamic Body (width, height, mass)
    Body* box = new Body(2.0f, 2.0f, 1.0f);
    box->position = { 0.0f, -10.0f }; // Start in the air
    
    // 3. Add to the World
    world.AddBody(box);

    // 4. Simulation Loop
    float dt = 1.0f / 60.0f;
    for (int i = 0; i < 60; ++i) {
        world.Step(dt);
        std::cout << "Box Y Position: " << box->position.y << std::endl;
    }

    return 0;
}
