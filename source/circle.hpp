#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>
#include "vec2.hpp"

class Circle {
    public:
    float circumfrence(radius) {
        return 2*pi*radius;
    }
    private:
    float radius = 0.0f;
    Vec2 origin{};

}



#endif // CIRCLE_HPP