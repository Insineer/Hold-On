#include "Hero.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Hero::Hero() {
    shape.reset(new uf::Circle(30));
    shapeCircle = dynamic_cast<uf::Circle *>(shape.get());

    speed = 50;

    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("Hero"));
    sprite->setTextureRect(sf::IntRect(0, 0, 100, 100));
    sprite->setOrigin(uf::vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
};

void Hero::Update(sf::Time timeElapsed) {
    Mob::Update(timeElapsed);
}

void Hero::SetMoveOrder(uf::vec2f order) {
    setMoveDirection(order);
}

void Hero::SetViewDirection(float angle) {
    shape->SetRotation(angle);
}