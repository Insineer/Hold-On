#include "Rectangle.hpp"

#include "Useful/Geometry/Geometry.hpp"

using namespace uf;

bool Rectangle::Intersect(Shape *shape) {
    if (auto circle = dynamic_cast<Circle *>(shape))
        return uf::Intersect(*this, *circle);
    if (auto rect = dynamic_cast<Rectangle *>(shape))
        return uf::Intersect(*this, *rect);
    return false;
}