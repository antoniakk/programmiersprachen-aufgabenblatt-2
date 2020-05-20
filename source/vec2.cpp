#include <iostream>
#include "vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& v) {
    x += v.x;
    y += v.y;
    return *this;
};
Vec2& Vec2::operator-=(Vec2 const& v) {
    x -= v.x;
    y -= v.y;
    return *this;
};
Vec2& Vec2::operator*=(float s) {
    x *= s;
    y *= s;
    return *this;
};
Vec2& Vec2::operator/=(float s) {
    x /= s;
    y /= s;
    return *this;
}; 



Vec2 operator+(Vec2 const& u, Vec2 const& v) {
    Vec2 w{u};
    w += v;
    return w;
};
Vec2 operator-(Vec2 const& u, Vec2 const& v) {
    Vec2 w{u};
    w -= v;
    return w;
};

Vec2 operator*(Vec2 const& v, float s) {
    Vec2 w{v};
    w *= s;
    return w;
};
Vec2 operator/(Vec2 const& v, float s) {
    Vec2 w{v};
    w /= s;
    return w;
};
Vec2 operator*(float s, Vec2 const& v) {
    return v*s;
};