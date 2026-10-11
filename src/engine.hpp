#pragma once

#include <array>
#include "allocators.hpp"
#include "body.hpp"


constexpr float MIN_FORCE = 0.01f;
constexpr int MAX_BODIES = 100;
constexpr double G = 6.67430e-11;


typedef struct Hitcircle {
    float radius;
} Hitcircle;


class Engine {
public:
    SParray<Body, MAX_BODIES> planets;
    Engine() = default;
    ~Engine() = default;
    void Step();
    void Create(const Body &bodydef);
    void Delete();

private:
    float dt;
    SParray<Hitcircle, MAX_BODIES> hitcircles;
    void DetectCollisions();
    void Integrate();
};