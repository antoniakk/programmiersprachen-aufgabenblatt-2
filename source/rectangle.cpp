#include "rectangle.hpp"

 Rectangle::Rectangle() : min_{0.0, 0.0}, max_{1.0, 1.0}, color_{0, 0, 0} {}; 

 Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) : min_{min}, max_{max}, color_{color} {};

 float Rectangle::circumfrence(Vec2 const& min, Vec2 const& max) const {
     return (max.y - min.y)*(max.x - min.x);
 };

 void Rectangle::draw(Window const& window) const {
        window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.b, color_.g, 1.0); 
        window.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.b, color_.g, 1.0); 
        window.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.b, color_.g, 1.0); 
        window.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.b, color_.g, 1.0); 
    }