#pragma once

#include <list>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "Useful/Geometry/Vec2f.hpp"
#include "Useful/Memory.hpp"

namespace sf {
    class RenderTarget;
    class RectangleShape;
    class Time;
}

class Object;
class Hero;
class Mob;

class Map {
private:
    uf::vec2f size;
    std::list<uf::uptr<Object>> objects;
    Hero *hero;

public:
    Map();

    void Update(sf::Time);
    void Draw(sf::RenderTarget *target);

    Hero *GetHero() const;

    ~Map();
};
