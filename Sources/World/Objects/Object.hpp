#pragma once

#include "Useful/Vec2f.hpp"
#include "Useful.hpp"

namespace sf {
    class RenderTarget;
    class Sprite;
}

class Object {
protected:
    float angle; //Has to be between -180 and 180
    vec2f position;
    uptr<sf::Sprite> sprite;

public:
    virtual void Update() = 0;
    virtual void Draw(sf::RenderTarget *target, vec2f targetCoord) const = 0;

    void SetPosition(vec2f position);
    void SetPosition(float x, float y);
    vec2f GetPosition() const;
    ~Object();
};