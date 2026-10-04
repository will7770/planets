#pragma once
#include "src/Vector.hpp"

struct Body {
    Vector2 position;
    Vector2 netForce;
    Vector2 acceleration;
    Vector2 velocity;
    float radius;
    float mass;
    float rotation;

    Body(
        Vector2 pos = ZeroVector2,
        float radius = 1.0f,
        float rotation = 0.0f,
        float mass = 1.0f,
        Vector2 initVelocity = ZeroVector2
    ) 
    : position(pos) , radius(radius), rotation(rotation), mass(mass), velocity(initVelocity) {}

    ~Body() = default;

    void OnStart() {}
    void Update(float deltaTime) {}
    void LateUpdate(float deltaTime) {}
    void OnStop() {}
};