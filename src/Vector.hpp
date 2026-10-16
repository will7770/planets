#pragma once
#include <cmath>
#include <iostream>

struct Vector2 {
    float X, Y;

    constexpr Vector2(float x = 0, float y = 0) noexcept : X(x), Y(y) {}
};

inline constexpr Vector2 ZeroVector2{ 0.0f, 0.0f};
inline constexpr Vector2 OneVector2{ 1.0f, 1.0f};
inline constexpr Vector2 UpVector2{ 0.0f, 1.0f};
inline constexpr Vector2 RightVector2{ 1.0f, 0.0f};

inline constexpr float Dot(const Vector2& a, const Vector2& b) noexcept {
    return a.X * b.X + a.Y * b.Y;
}
inline constexpr float Cross(const Vector2& a, const Vector2&b) {
    return a.X * b.Y - a.Y * b.X;
}
inline constexpr float LengthSquared(const Vector2& v) noexcept{
    return Dot(v, v);
}
inline float Length(const Vector2& v) noexcept{
    return std::sqrt(LengthSquared(v));
}

inline constexpr Vector2& operator+=(Vector2& a, const Vector2& b) noexcept {
    a.X += b.X; a.Y += b.Y;
    return a;
}
inline constexpr Vector2& operator-=(Vector2& a, const Vector2& b) noexcept {
    a.X -= b.X; a.Y -= b.Y;
    return a;
}
inline constexpr Vector2& operator*=(Vector2& v, float scalar) noexcept {
    v.X *= scalar; v.Y *= scalar;
    return v;
}
inline constexpr Vector2& operator/=(Vector2& v, float scalar) {
    v.X /= scalar; v.Y /= scalar;
    return v;
}
inline constexpr Vector2& operator*=(Vector2& a, const Vector2& b) noexcept {
    a.X *= b.X; a.Y *= b.Y;
    return a;
}
inline constexpr Vector2& operator/=(Vector2& a, const Vector2& b) {
    a.X /= b.X; a.Y /= b.Y;
    return a;
}

inline constexpr Vector2 operator+(Vector2 a, const Vector2& b) noexcept {
    a += b;
    return a;
}
inline constexpr Vector2 operator-(Vector2 a, const Vector2& b) noexcept{
    a -= b;
    return a;
}
inline constexpr Vector2 operator-(const Vector2& v) noexcept{
    return Vector2(-v.X, -v.Y);
}
inline constexpr Vector2 operator*(Vector2 v, float scalar) noexcept {
    v *= scalar;
    return v;
}
inline constexpr Vector2 operator*(float scalar, const Vector2& v) noexcept {
    return v * scalar;
}
inline constexpr Vector2 operator/(Vector2 v, float scalar) {
    v /= scalar;
    return v;
}
inline constexpr Vector2 operator*(Vector2 a, const Vector2& b) noexcept {
    a *= b;
    return a;
}
inline constexpr Vector2 operator/(Vector2 a, const Vector2& b) {
    a /= b;
    return a;
}

inline std::ostream& operator<<(std::ostream& os, const Vector2& v) {
    os << "(" << v.X << ", " << v.Y << ")";
    return os;
}
inline constexpr bool operator==(const Vector2& a, const Vector2& b) noexcept {
    return a.X == b.X && a.Y == b.Y;
}
inline constexpr bool operator!=(const Vector2& a, const Vector2& b) noexcept {
    return !(a == b);
}

inline Vector2 Normalize(const Vector2& v) noexcept {
    float len = Length(v);
    if (len > 0.0f) {
        return v / len;
    }
    return ZeroVector2;
}