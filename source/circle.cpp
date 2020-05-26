#include <cmath>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle() : 
    radius_{1.0}, 
    center_{}, 
    color_{} {};

Circle::Circle(float radius, Vec2 const& center, Color const& color) : 
    radius_{radius}, 
    center_{center}, 
    color_{color} {};

Vec2 Circle::get_center() const {
    return center_;
}

float Circle::circumfrence(float radius) const {
    return 2*M_PI*radius;
}

void Circle::draw(Window const& window, float thickness) const {
    Vec2 start{radius_, 0.0};
    Vec2 end{};
    Mat2 rotation = make_rotation_mat2(M_PI/60);
    for (float theta = 0; theta <= 2*M_PI; theta += M_PI/60) {
        end = rotation*start;
        window.draw_line(start.x + center_.x, start.y + center_.y, end.x + center_.x, end.y + center_.y, color_.r, color_.b, color_.g, thickness);
        start = end;
    }
}

bool Circle::is_inside(Vec2 const& point) const {
    if ((pow(center_.x - point.x, 2) + pow(center_.y - point.y, 2)) >= pow(radius_,2)) {
        return false;
    }
    return true;
};
