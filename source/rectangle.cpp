#include "rectangle.hpp"


 Rectangle::Rectangle() : min_{0.0, 0.0}, max_{1.0, 1.0}, color_{0, 0, 0} {}; 

 Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color) : min_{min}, max_{max}, color_{color} {};

 float Rectangle::circumfrence(Vec2 const& min, Vec2 const& max) const {
     return (max.y - min.y)*(max.x - min.x);
 };