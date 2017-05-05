#pragma once

#include "Object.hpp"

namespace uf {
    class Circle;
}

class Mob : public Object {
private:
    uf::vec2f moveDirection;
protected:
    float speed;
    uf::Circle *shapeCircle;

    void setMoveDirection(uf::vec2f moveDirection);

public:
    Mob();

    virtual void Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const final;
    virtual void Update(sf::Time);
};