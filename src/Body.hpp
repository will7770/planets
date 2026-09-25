#pragma once
#include "src/Vector.hpp"

struct Body {
    Vector2 Position;
    Vector2 Scale;
    Vector2 netForce;
    Vector2 acceleration;
    Vector2 velocity;
    float mass;
    float Rotation;

    Body(
        Vector2 pos = ZeroVector2,
        Vector2 scale = OneVector2, 
        float rotation = 0,
        float mass = 1,
        Vector2 initVelocity = ZeroVector2
    ) 
    : Position(pos) , Scale(scale), Rotation(rotation), mass(mass), velocity(initVelocity) {}

    ~Body() = default;

    void OnStart() {}
    void Update(float deltaTime) {}
    void LateUpdate(float deltaTime) {}
    void OnStop() {}
};