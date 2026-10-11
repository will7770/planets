#include <new>
#include <cmath>
#include "engine.hpp"


// could probably use a no copy approach
void Engine::Create(const Body &bodydef) {
    Body *newbody = planets.alloc();
    Hitcircle *hitcircle = hitcircles.alloc();

    ::new (newbody) Body(std::move(bodydef));

    float radius = std::sqrt((G*newbody->mass)/MIN_FORCE);

    *hitcircle = Hitcircle{.radius = radius};
}