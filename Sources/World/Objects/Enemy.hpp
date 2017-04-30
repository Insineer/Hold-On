#pragma once

#include "Mob.hpp"

class Enemy : public Mob {
public:
    Enemy();
    virtual void Update(sf::Time) final;
};


