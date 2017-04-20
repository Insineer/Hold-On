#pragma once

#include <cmath>
#include <memory>

#include "Geometry.hpp"

template <class T>
using uptr = std::unique_ptr<T>;

int Sgn(float t);