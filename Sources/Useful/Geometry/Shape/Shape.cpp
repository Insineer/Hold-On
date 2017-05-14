#include "Shape.hpp"

using namespace uf;

Shape::Shape() : angle(0) { }

void Shape::Rotate(const float angle) { SetRotation(GetRotation() + angle); }
void Shape::SetRotation(const float angle) { this->angle = angle; }