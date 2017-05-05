#pragma once

#include "Mob.hpp"

namespace uf {
    class Circle;
}

class Hero : public Mob {
public:
    Hero();
    virtual void Update(sf::Time) final;

    void SetMoveOrder(uf::vec2f order);
    void SetViewDirection(float angle);
};
