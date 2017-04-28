#pragma once

#include <list>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "Useful/Geometry/Vec2f.hpp"
#include "World/Objects/Object.hpp"

namespace sf {
    class RenderTarget;
    class RectangleShape;
}
class Hero;
class Mob;

class Map {
private:
    uf::vec2f size;
    std::list<uf::uptr<Object>> objects;
    Hero *hero;

public:
    Map();

    void Update();
    void Draw(sf::RenderTarget *target);

    Hero *GetHero() const;
};
