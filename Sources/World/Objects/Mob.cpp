#include "Mob.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Hero.hpp"
#include "World/Map.hpp"
#include "Useful/Shape/Circle.hpp"

#define EPS 0.1

Mob::Mob() {
    velocity = 1;
    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("monstr1"));
    sprite->setTextureRect(sf::IntRect(10, 10, 40, 40));
    angle = 0;
    radius = 20;

    shape.reset(new Circle(radius));
}

void Mob::Draw(sf::RenderTarget *target, vec2f targetCoord) const {
    sprite->setPosition(targetCoord - vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));
    //sprite->setPosition(targetCoord);
    sprite->setRotation(angle);
    target->draw(*sprite);
}

void Mob::Update() {
    shape->SetPosition(position);
    shape->SetRotation(angle);
    Hero *hero = Game::Get()->GetMap()->GetHero();
    if (shape->Intersect(hero->GetShape())) {
        std::cout << "GOTCHA" << std::endl;
        return;
    }
    std::pair<bool, vec2f> shift = GetShift(hero->GetPosition() - position);
    if (shift.first)
        SetPosition(position + shift.second);
}

std::pair<bool, vec2f> Mob::GetShift(const vec2f &diff) {
    if (std::abs(diff.y) < EPS && std::abs(diff.x) < EPS)
        return std::make_pair(false, vec2f());
    if (std::abs(diff.y) < EPS)
        return std::make_pair(true, vec2f(velocity * Sgn(diff.x), position.y));

    float coef = diff.x /diff.y;

    float y = (velocity / std::sqrt(coef * coef + 1)) * Sgn(diff.y);
    return std::make_pair(true, vec2f(coef * y, y));
}