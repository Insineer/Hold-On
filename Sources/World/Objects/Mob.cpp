#include "Mob.hpp"

#include <SFML/Graphics.hpp>

#include "Useful/Math.hpp"
#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Hero.hpp"
#include "World/Map.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Mob::Mob() {

}

void Mob::Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const {
    sprite->setPosition(targetCoord - uf::vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
    //sprite->setPosition(targetCoord);
    sprite->setRotation(shape->GetRotation());
    target->draw(*sprite);
}

void Mob::Update(sf::Time timeElapsed) {
    SetPosition(shape->GetPosition() + moveDirection * speed * timeElapsed.asSeconds());
    moveDirection = uf::vec2f();
}