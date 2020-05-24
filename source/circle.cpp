#include <cmath>
#include "circle.hpp"

Circle::Circle() : radius_{0.0}, origin_{0, 0}, color_{0, 0, 0} {};

Circle::Circle(float radius, Vec2 const& origin, Color const& color) : radius_{radius}, origin_{origin}, color_{color} {};

float Circle::circumfrence(float radius) const {
    return 2*M_PI*radius;
}