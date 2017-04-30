#pragma once

#include "Useful/Geometry/Vec2f.hpp"
#include "Useful/Memory.hpp"

namespace sf {
    class RenderTarget;
    class Sprite;
    class Time;
}
namespace uf {
    class Shape;
}

class Object {
protected:
    uf::uptr<uf::Shape> shape;
    uf::uptr<sf::Sprite> sprite;

public:
    virtual void Update(sf::Time) = 0;
    virtual void Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const = 0;

    void SetPosition(uf::vec2f position);
    void SetPosition(float x, float y);
    uf::vec2f GetPosition() const;
    uf::Shape *GetShape() const;

    ~Object();
};