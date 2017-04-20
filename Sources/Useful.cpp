#include "Useful.hpp"

int Sgn(float t) { return -(std::signbit(t) * 2 - 1); }