#pragma once

#include "Shape/Circle.hpp"
#include "Shape/Rectangle.hpp"

namespace uf {

    bool Intersect(const Circle &, const Circle &);
    bool Intersect(const Rectangle &, const Rectangle &);
    bool Intersect(const Circle &, const Rectangle &);
    bool Intersect(const Rectangle &, const Circle &);
}