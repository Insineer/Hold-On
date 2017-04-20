#pragma once

#include "Useful.hpp"

class Circle;
class Rectangle;

bool Intersect(const Circle &, const Circle &);
bool Intersect(const Rectangle &, const Rectangle &);
bool Intersect(const Circle &, const Rectangle &);
bool Intersect(const Rectangle &, const Circle &);