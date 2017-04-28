#include "Circle.hpp"

#include "Useful/Geometry/Geometry.hpp"
#include "Rectangle.hpp"

using namespace uf;

bool Circle::Intersect(Shape *shape) {
    if (auto circle = dynamic_cast<Circle *>(shape))
        return uf::Intersect(*this, *circle);
    if (auto rect = dynamic_cast<Rectangle *>(shape))
        return uf::Intersect(*this, *rect);
    return false;
}