#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
    public:
    Circle();
    Circle(float radius, Vec2 const& center, Color const& color);
    Vec2 get_center() const;
    float circumfrence(float radius) const;
    void draw(Window const& window, float thickness = 1.0) const;
    bool is_inside(Vec2 const& point) const;
    
    private:
    float radius_;
    Vec2 center_;
    Color color_;

};



#endif // CIRCLE_HPP
