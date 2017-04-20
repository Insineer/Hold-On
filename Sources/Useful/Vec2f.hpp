#pragma once

#include <SFML/System/Vector2.hpp>

#include "cmath"
#include "iostream"

struct vec2f {
    float x;
    float y;

    vec2f();
    vec2f(float x, float y);
    vec2f(const vec2f& vect);
    vec2f(const sf::Vector2f &vect);
    vec2f(const sf::Vector2u &vect);
    vec2f operator+(const vec2f &other);
    vec2f operator-(const vec2f &other);
    vec2f operator+=(vec2f &other);
    vec2f operator-=(vec2f &other);
    vec2f operator*(float a) const;
    vec2f operator*=(float a);
    vec2f operator/(float a) const;
    vec2f operator/=(float a);

    operator sf::Vector2f() const;
    operator sf::Vector2u() const;

    friend std::ostream& operator<<(std::ostream& os, const vec2f& vec);
};

float Dist(const vec2f &vec);