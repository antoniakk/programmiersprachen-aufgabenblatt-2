#include <cmath>
#include "circle.hpp"
#include "window.hpp"

Circle::Circle() : 
    radius_{0.0}, 
    origin_{0, 0}, 
    color_{0, 0, 0} {};

Circle::Circle(float radius, Vec2 const& origin, Color const& color) : 
    radius_{radius}, 
    origin_{origin}, 
    color_{color} {};

float Circle::circumfrence(float radius) const {
    return 2*M_PI*radius;
}

void Circle::draw(Window const& window) const {
    Vec2 start{origin_.x + radius_, origin_.y};
    Vec2 end{};
    for (float theta = 0; theta <= 2*M_PI; theta += M_PI/8) {
        end.x = radius_*cos(theta);
        end.y = radius_*sin(theta);
        window.draw_line(start.x, start.y, end.x, end.y, color_.r, color_.b, color_.g, 1.0);
        start.x = end.x;
        start.y = end.y;
    }
}