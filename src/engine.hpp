#pragma once

#include <array>
#include <vector>
#include "allocators.hpp"
#include "body.hpp"


constexpr float MIN_FORCE = 0.01f;
constexpr int MAX_BODIES = 100;
constexpr double G = 6.67430e-11;


typedef struct Hitcircle {
    float radius;
} Hitcircle;


struct Contact;


class Engine {
public:
    SParray<Body, MAX_BODIES> planets;
    Engine() = default;
    ~Engine() = default;
    void Step(float dt);
    int Create(Body &bodydef);
    void Delete(int bodyidx);

private:
    SParray<Hitcircle, MAX_BODIES> hitcircles;
    void DetectCollisions(std::vector<Contact> &buffer);
    void Integrate(Contact cont, float dt);
};