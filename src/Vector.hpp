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
//Vector3

struct Vector3 {
    float X, Y, Z;

    constexpr Vector3(float x = 0, float y = 0, float z = 0) noexcept : X(x), Y(y), Z(z) {}
};

inline constexpr Vector3 ZeroVector3{ 0.0f, 0.0f, 0.0f };
inline constexpr Vector3 OneVector3{ 1.0f, 1.0f, 1.0f };
inline constexpr Vector3 UpVector3{ 0.0f, 1.0f, 0.0f };
inline constexpr Vector3 RightVector3{ 1.0f, 0.0f, 0.0f };
inline constexpr Vector3 ForwardVector3{ 0.0f, 0.0f, 1.0f };

inline constexpr float Dot(const Vector3& a, const Vector3& b) noexcept {
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}
inline constexpr Vector3 Cross(const Vector3& a, const Vector3& b) noexcept {
    return Vector3{
        a.Y * b.Z - a.Z * b.Y,
        a.Z * b.X - a.X * b.Z,
        a.X * b.Y - a.Y * b.X
    };
}
inline constexpr float LengthSquared(const Vector3& v) noexcept {
    return Dot(v, v);
}

inline float Length(const Vector3& v) noexcept {
    return std::sqrt(LengthSquared(v));
}

inline constexpr Vector3& operator+=(Vector3& a, const Vector3& b) noexcept {
    a.X += b.X;
    a.Y += b.Y;
    a.Z += b.Z;
    return a;
}
inline constexpr Vector3& operator-=(Vector3& a, const Vector3& b) noexcept {
    a.X -= b.X;
    a.Y -= b.Y;
    a.Z -= b.Z;
    return a;
}
inline constexpr Vector3& operator*=(Vector3& v, float scalar) noexcept {
    v.X *= scalar;
    v.Y *= scalar;
    v.Z *= scalar;
    return v;
}
inline constexpr Vector3& operator/=(Vector3& v, float scalar) {
    v.X /= scalar;
    v.Y /= scalar;
    v.Z /= scalar;
    return v;
}
inline constexpr Vector3& operator*=(Vector3& v, const Vector3& other) noexcept {
    v.X *= other.X;
    v.Y *= other.Y;
    v.Z *= other.Z;
    return v;
}

inline constexpr Vector3& operator/=(Vector3& v, const Vector3& other) {
    v.X /= other.X;
    v.Y /= other.Y;
    v.Z /= other.Z;
    return v;
}


inline constexpr Vector3 operator+(Vector3 a, const Vector3& b) noexcept {
    a += b;
    return a;
}
inline constexpr Vector3 operator-(Vector3 a, const Vector3& b) noexcept {
    a -= b;
    return a;
}
inline constexpr Vector3 operator-(const Vector3& v) noexcept {
    return Vector3{-v.X, -v.Y, -v.Z};
}

inline constexpr Vector3 operator*(Vector3 v, float scalar) noexcept {
    v *= scalar;
    return v;
}
inline constexpr Vector3 operator*(float scalar, const Vector3& v) noexcept {
    return v * scalar;
}
inline constexpr Vector3 operator/(Vector3 v, float scalar) {
    v /= scalar;
    return v;
}
inline constexpr Vector3 operator*(Vector3 a, const Vector3& b) noexcept {
    a *= b;
    return a;
}

inline constexpr Vector3 operator/(Vector3 a, const Vector3& b) {
    a /= b;
    return a;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.X << ", " << v.Y << ", " << v.Z << ")";
    return os;
}
inline constexpr bool operator==(const Vector3& a, const Vector3& b) noexcept {
    return a.X == b.X && a.Y == b.Y && a.Z == b.Z;
}
inline constexpr bool operator!=(const Vector3& a, const Vector3& b) noexcept {
    return !(a == b);
}

inline Vector3 Normalize(const Vector3& v) noexcept {
    float len = Length(v);
    if (len > 0.0f) {
        return v / len;
    }
    return ZeroVector3;
}