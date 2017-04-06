#include "Object.hpp"

#include <SFML/Graphics.hpp>

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