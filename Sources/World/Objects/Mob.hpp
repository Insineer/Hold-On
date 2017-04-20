#pragma once

#include "Object.hpp"

namespace sf {
    class CircleShape;
}

class Mob : public Object {
private:
    float radius;
    float velocity;

    std::pair<bool, vec2f> GetShift(const vec2f& diff);
public:
    Mob();

    virtual void Draw(sf::RenderTarget *target, vec2f targetCoord) const final;
    virtual void Update() final;
};