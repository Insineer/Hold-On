#include "Object.hpp"

#include "Useful/Shape/Shape.hpp"

#include <SFML/Graphics.hpp>

Shape *Object::GetShape() const {
    return shape.get();
}

vec2f Object::GetPosition() const {
    return position;
}

void Object::SetPosition(vec2f position) {
    this->position = position;
}

void Object::SetPosition(float x, float y) {
    this->position = vec2f(x, y);
}

Object::~Object() {}