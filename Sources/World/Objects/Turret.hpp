#pragma once

#include "Object.hpp"

namespace uf {
    class Rectangle;
}

class Turret : public Object {
protected:
    uf::Rectangle *shapeRectangle;

    float defenseRadius;
    float rotationSpeed;

    bool active;

public:
    explicit Turret(float defenseRadius = 0);

    virtual void Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const final;
    virtual void Update(sf::Time);

    void Set();
};

