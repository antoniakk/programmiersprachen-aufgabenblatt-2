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
    void draw(Window const& window) const;
    void draw(Window const& window, float thickness) const;
    void draw(Window const& window, bool highlight_color) const;

    private:
    Vec2 min_{};
    Vec2 max_{1.0, 1.0};
    Color color_{};
};









#endif