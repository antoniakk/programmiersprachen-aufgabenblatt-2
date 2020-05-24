#include "rectangle.hpp"


 Rectangle::Rectangle() : min_{0.0, 0.0}, max_{1.0, 1.0} {}; 

 Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) : min_{min}, max_{max} {};

 float Rectangle::circumfrence(Vec2 const& min, Vec2 const& max) const {
     return (max.y - min.y)*(max.x - min.x);
 };