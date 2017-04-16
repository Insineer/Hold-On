#pragma once

#include <list>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "Useful/Vec2f.hpp"
#include "World/Objects/Object.hpp"

namespace sf {
    class RenderTarget;
    class RectangleShape;
}
class Hero;
class Mob;

class Map {
private:
    vec2f size;
    std::list<uptr<Object>> objects;
    Hero *hero;

public:
    Map();

    void Update();
    void Draw(sf::RenderTarget *target);

    Hero *GetHero() const;
};
