#include "Math.hpp"

#include <cmath>

int uf::sgn(float t) { return -(std::signbit(t) * 2 - 1); }