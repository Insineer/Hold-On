#pragma once

#include <SFML/System/String.hpp>

class Hero;

class Player {
private:
    sf::String name;
    Hero *hero;

public:
    void SetHero(Hero *hero);
    ~Player();
};


