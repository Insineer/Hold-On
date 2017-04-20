#include "Circle.hpp"

#include "Useful.hpp"
#include "Useful/Shape/Rectangle.hpp"

bool Circle::Intersect(Shape *shape) {
    if (auto circle = dynamic_cast<Circle *>(shape))
        return ::Intersect(*this, *circle);
    if (auto rect = dynamic_cast<Rectangle *>(shape))
        return ::Intersect(*this, *rect);
    return false;
}