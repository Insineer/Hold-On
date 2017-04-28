#include "Mob.hpp"

#include <SFML/Graphics.hpp>

#include "Useful/Math.hpp"
#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Hero.hpp"
#include "World/Map.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

#define EPS 0.1

Mob::Mob() {
    shape.reset(new uf::Circle(20));
    shapeCircle = dynamic_cast<uf::Circle *>(shape.get());
    velocity = 1;
    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("monstr1"));
    sprite->setTextureRect(sf::IntRect(10, 10, 40, 40));
}

void Mob::Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const {
    sprite->setPosition(targetCoord - uf::vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
    //sprite->setPosition(targetCoord);
    sprite->setRotation(shape->GetRotation());
    target->draw(*sprite);
}

void Mob::Update() {
    Hero *hero = Game::Get()->GetMap()->GetHero();
    if (shape->Intersect(hero->GetShape())) {
        std::cout << "GOTCHA" << std::endl;
        return;
    }
    SetPosition(shape->GetPosition() + getShift(hero->GetPosition() - shape->GetPosition()));
}

uf::vec2f Mob::getShift(const uf::vec2f &diff) {
    if (diff.length() < EPS)
        return uf::vec2f();

    float k = diff.x / diff.y;

    float y = (velocity / std::sqrt(k * k + 1)) * uf::sgn(diff.y);
    return uf::vec2f(k * y, y);
}