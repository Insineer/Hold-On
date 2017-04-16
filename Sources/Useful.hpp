#pragma once

#include <cmath>
#include <memory>

namespace sf {
    class CircleShape;
    class RectangleShape;
}

template <class T>
using uptr = std::unique_ptr<T>;

int GetSign(float t);

bool Intersect(const sf::CircleShape &, const sf::CircleShape &);
bool Intersect(const sf::RectangleShape &, const sf::RectangleShape &);
bool Intersect(const sf::CircleShape &, const sf::RectangleShape &);
bool Intersect(const sf::RectangleShape &, const sf::CircleShape &);
