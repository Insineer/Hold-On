#include "Hero.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Hero::Hero() {
    shape.reset(new uf::Circle(27));
    shapeCircle = dynamic_cast<uf::Circle *>(shape.get());
    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("armysheet"));
    sprite->setTextureRect(sf::IntRect(385, 25, 80, 54));
};

void Hero::Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const {
    sprite->setPosition(targetCoord - uf::vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
    //sprite->setPosition(targetCoord);
    sprite->setRotation(shape->GetRotation());
    target->draw(*sprite);
}

void Hero::Update() {

}