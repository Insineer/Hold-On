#include "Object.hpp"

#include <SFML/Graphics.hpp>

#include "Useful/Geometry/Shape/Shape.hpp"

Shape *Object::GetShape() const {
    return shape.get();
}

uf::vec2f Object::GetPosition() const {
    return shape->GetPosition();
}

void Object::SetPosition(uf::vec2f position) {
    shape->SetPosition(position);
}

void Object::SetPosition(float x, float y) {
    shape->SetPosition(x, y);
}

Object::~Object() { }