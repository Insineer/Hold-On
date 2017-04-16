#include "Vec2f.hpp"

#include <utility>

vec2f::vec2f() : x(0), y(0) {}
vec2f::vec2f(float x, float y) : x(x), y(y) {}
vec2f::vec2f(sf::Vector2f vect) : x(vect.x), y(vect.y) {}
vec2f::vec2f(sf::Vector2u vect) : x(vect.x), y(vect.y) {}

vec2f vec2f::operator+(const vec2f &other) {
    return vec2f(x + other.x, y + other.y);
}
vec2f vec2f::operator-(const vec2f &other) {
    return vec2f(x - other.x, y - other.y);
}
vec2f vec2f::operator+=(vec2f &other) {
    x += other.x;
    y += other.y;
    return std::move(*this);
}
vec2f vec2f::operator-=(vec2f &other) {
    x -= other.x;
    y -= other.y;
    return std::move(*this);
}
vec2f vec2f::operator*(float a) const {
    return vec2f(x * a, y * a);
}
vec2f vec2f::operator*=(float a) {
    x *= a;
    y *= a;
    return std::move(*this);
}
vec2f vec2f::operator/(float a) const {
    return vec2f(x / a, y / a);
}
vec2f vec2f::operator/=(float a) {
    x /= a;
    y /= a;
    return std::move(*this);
}

vec2f::operator sf::Vector2f() const {
    return sf::Vector2f(x, y);
}
vec2f::operator sf::Vector2u() const {
    return sf::Vector2u((unsigned)x, (unsigned)y);
}

std::ostream& operator<<(std::ostream& os, const vec2f& vec)
{
    os << "(" << vec.x << ", " << vec.y << ')';
    return os;
}