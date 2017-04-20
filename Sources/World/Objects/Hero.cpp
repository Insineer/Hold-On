#include "Hero.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Useful/Shape/Circle.hpp"

Hero::Hero() {
    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("armysheet"));
    sprite->setTextureRect(sf::IntRect(385, 25, 80, 54));
    angle = 0;
    radius = 27;

    shape.reset(new Circle(radius));
};

void Hero::Draw(sf::RenderTarget *target, vec2f targetCoord) const {
    sprite->setPosition(targetCoord - vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
    //sprite->setPosition(targetCoord);
    sprite->setRotation(angle);
    target->draw(*sprite);
}

void Hero::Update() {
    shape->SetPosition(position);
    shape->SetRotation(angle);
}