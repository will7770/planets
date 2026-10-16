#pragma once

#include <span>
#include <vector>
#include "Vector.hpp"
#include "SDL3/SDL.h"

struct Hitcircle;

class Renderer {
public:
    static constexpr unsigned int kMaxVertices = 400000;
    SDL_GPUDevice* gpuDevice = nullptr;
    int screenHeight, screenWidth;

    Renderer(int sH = 1200, int sW = 750) : screenHeight(sH), screenWidth(sW) {}
    ~Renderer();

    bool SDLInitialize();
    void SDLShutDown();

    void RenderScenary(std::span<Hitcircle>& radii, std::span<Vector2>& worldPositions);
private:
    
};