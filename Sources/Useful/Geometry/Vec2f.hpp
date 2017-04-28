#pragma once

#include "cmath"
#include "iostream"

namespace sf {
    template<class T>
    class Vector2;
    typedef Vector2<float> Vector2f;
    typedef Vector2<unsigned> Vector2u;
}

namespace uf {

    struct vec2f {
        float x;
        float y;

        vec2f();
        vec2f(float x, float y);
        vec2f(const vec2f &vect);
        vec2f(const sf::Vector2f &vect);
        vec2f(const sf::Vector2u &vect);

        float length() const;

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

        friend std::ostream &operator<<(std::ostream &os, const vec2f &vec);
    };

    float length(const vec2f &vec);
}