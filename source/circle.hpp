#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
    public:
    Circle();
    Circle(float radius, Vec2 const& origin, Color const& color);
    float circumfrence(float radius) const;
    void draw(Window const& window, float thickness = 1.0) const;
    bool is_inside(Vec2 const& point) const;
    
    private:
    float radius_;
    Vec2 origin_;
    Color color_;

};



#endif // CIRCLE_HPP