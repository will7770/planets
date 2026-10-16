#include "engine.hpp"
#include "renderer.hpp"
#include <algorithm>
#include <iostream>

Renderer::Renderer(int sW, int sH)
    : screenWidth(sW), screenHeight(sH)
{
    pixels.resize(screenHeight * screenWidth);
}
Renderer::~Renderer() {
    SDLShutdown();
}

bool Renderer::SDLInitialize() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow(
        "GameEngine",
        screenWidth, screenHeight,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
        screenWidth, screenHeight);
    if (!texture) {
        std::cerr << "Texture creation failed: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}
void Renderer::SDLShutdown() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

void Renderer::RenderScenery(std::span<const Hitcircle> radii, std::span<const Vector2> worldPositions) {
    ClearScreen(Colors::Black);
    std::size_t count = std::min(radii.size(), worldPositions.size());
    for(std::size_t i = 0; i < count; i++) {
        DrawCircle(worldPositions[i], radii[i].radius);
    }
    SDL_UpdateTexture(texture, nullptr, pixels.data(), screenWidth * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Renderer::DrawCircle(Vector2 pos, float radius, Color color) {
    const int cx = static_cast<int>(screenWidth * 0.5f + pos.X + 0.5f);
    const int cy = static_cast<int>(screenHeight * 0.5f - pos.Y + 0.5f);
    const int r = static_cast<int>(radius + 0.5f);

    const uint32_t pixel = ToUint32(color);
    const unsigned int radiusSquared = r*r;

    const int minX = std::max(0, cx - r);
    const int maxX = std::min(screenWidth - 1, cx + r);
    const int minY = std::max(0, cy - r);
    const int maxY = std::min(screenHeight - 1, cy + r);

    for (int y = minY; y <= maxY; ++y)
    {
        const unsigned int rowOffset = y * screenWidth;
        for (int x = minX; x <= maxX; ++x)
        {
            const int dx = x - cx;
            const int dy = y - cy;

            if (dx * dx + dy * dy <= radiusSquared)
            {
                pixels[rowOffset + x] = pixel;
            }
        }
    }
}
void Renderer::ClearScreen(Color color) {
    uint32_t color32 = ToUint32(color);
    std::fill(pixels.begin(), pixels.end(), color32);
}