#include "Mob.hpp"

#include <SFML/Graphics.hpp>

#include "Useful/Math.hpp"
#include "Graphics/Window.hpp"
#include "Hero.hpp"
#include "World/Map.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Mob::Mob() {

}

void Mob::Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const {
    //sprite->setPosition(targetCoord - uf::vec2f(sprite->getTextureRect().width, sprite->getTextureRect().height) / 2);

    sprite->setPosition(targetCoord);
    sprite->setRotation(-float(shape->GetRotation() * 180 / M_PI));

    //std::cout << shape->GetRotation() * 180 / M_PI << std::endl;

    target->draw(*sprite);
}

void Mob::Update(sf::Time timeElapsed) {
    SetPosition(shape->GetPosition() + moveDirection * speed * timeElapsed.asSeconds());
    moveDirection = uf::vec2f();
}

void Mob::setMoveDirection(uf::vec2f moveDirection) {
    this->moveDirection = moveDirection;
}