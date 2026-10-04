#include <array>
#include "src/allocators.hpp"
#include "src/Body.hpp"


constexpr float CUTOFF_RADIUS = 0.01f;
constexpr int MAX_BODIES = 100;


typedef struct GravInfluence {
    float radius;
    int belongs_to;
} GravInfluence;


class Engine {
public:
    SParray<Body, MAX_BODIES> planets;
    ~Engine() = default;
    void Step();
    void Create();
    void Delete();

private:
    float dt;
    SParray<GravInfluence, MAX_BODIES> hitcircles;
    void DetectCollisions();
    void Integrate();
};