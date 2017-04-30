#include "Hero.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Hero::Hero() {
    shape.reset(new uf::Circle(27));
    shapeCircle = dynamic_cast<uf::Circle *>(shape.get());

    speed = 50;

    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("armysheet"));
    sprite->setTextureRect(sf::IntRect(385, 25, 80, 54));
};

void Hero::Update(sf::Time timeElapsed) {
    Mob::Update(timeElapsed);
}

void Hero::SetMoveOrder(uf::vec2f order) {
    moveDirection = order;
}