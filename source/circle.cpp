#include <cmath>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle() : 
    radius_{1.0}, 
    origin_{}, 
    color_{} {};

Circle::Circle(float radius, Vec2 const& origin, Color const& color) : 
    radius_{radius}, 
    origin_{origin}, 
    color_{color} {};

Vec2 Circle::get_origin() const {
    return origin_;
}

float Circle::circumfrence(float radius) const {
    return 2*M_PI*radius;
}

void Circle::draw(Window const& window, float thickness) const {
    Vec2 start{radius_, 0.0};
    Vec2 end{};
    Mat2 rotation = make_rotation_mat2(M_PI/60);
    for (float theta = 0; theta <= 2*M_PI; theta += M_PI/60) {
        end.x = (rotation*start).x;
        end.y = (rotation*start).y;
        window.draw_line(start.x + origin_.x, start.y + origin_.y, end.x + origin_.x, end.y + origin_.y, color_.r, color_.b, color_.g, thickness);
        start.x = end.x;
        start.y = end.y;
    }
}

bool Circle::is_inside(Vec2 const& point) const {
    if ((pow(origin_.x - point.x, 2) + pow(origin_.y - point.y, 2)) >= pow(radius_,2)) {
        return false;
    }
    return true;
};