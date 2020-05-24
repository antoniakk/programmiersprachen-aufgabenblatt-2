#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"

class Circle {
    public:
    Circle();
    Circle(float radius, Vec2 const& origin, Color const& color);
    float circumfrence(float radius) const;
    
    private:
    float radius_ = 0.0f;
    Vec2 origin_{};
    Color color_{};

};



#endif // CIRCLE_HPP