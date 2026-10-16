#include <new>
#include <cmath>
#include <vector>
#include "vector.hpp"
#include "engine.hpp"


typedef struct Contact {
    int body1;
    int body2;
} Contact;


// could probably use a no copy approach
int Engine::Create(Body &bodydef) {
    Body *newbody = planets.alloc();
    Hitcircle *hitcircle = hitcircles.alloc();

    ::new (newbody) Body(std::move(bodydef));

    float radius = std::sqrt((G*newbody->mass)/MIN_FORCE);
    *hitcircle = Hitcircle{.radius = radius};

    return planets.size-1;
}


void Engine::Delete(int bodyidx) {
    planets.dealloc(bodyidx);
    hitcircles.dealloc(bodyidx);
}


// currently naive O(n^2)
void Engine::DetectCollisions(std::vector<Contact> &buffer) {
    for (int i = 0; i < hitcircles.size-1; i++) {
        // cache pollution just for 1 class field of a planet
        Vector2 v = planets[i].position - planets[i+1].position;
        float dst = Length(v);

        if (dst < hitcircles[i].radius + hitcircles[i+1].radius) {
            buffer.push_back(Contact{i, i+1});
        }
    }
}


void Engine::Integrate(Contact cont, float dt) {
    
}


void Engine::Step(float dt) {
    static std::vector<Contact> contacts;

    DetectCollisions(contacts);

    for (int i = 0; i < contacts.size(); i++) {
        Integrate(contacts[i], dt);
    }
}