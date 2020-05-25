#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {
    public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
    float circumfrence(Vec2 const& min, Vec2 const& max) const;
    void draw(Window const& window, float thickness = 1.0) const;
    bool is_inside(Vec2 const& point) const;

    private:
    Vec2 min_;
    Vec2 max_;
    Color color_;
};









#endif