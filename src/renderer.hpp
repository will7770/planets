#pragma once

#include <span>
#include <vector>
#include "Vector.hpp"
#include "color.hpp"
#include "SDL3/SDL.h"

struct Hitcircle;

class Renderer {
public:
    static constexpr unsigned int kMaxVertices = 400000;
    SDL_GPUDevice* gpuDevice = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    int screenHeight, screenWidth;

    std::vector<unsigned int> pixels;  

    Renderer(int sW = 1200, int sH = 750);
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    bool SDLInitialize();
    void SDLShutdown();

    void RenderScenery(std::span<const Hitcircle> radii, std::span<const Vector2> worldPositions);
private:
    void ClearScreen(Color color = Colors::White);
    void DrawCircle(Vector2 position, float radius, Color color = Colors::Red);
};