#include "Enemy.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "Hero.hpp"
#include "World/Map.hpp"
#include "Useful/Geometry/Shape/Circle.hpp"

Enemy::Enemy() {
    shape.reset(new uf::Circle(20));
    shapeCircle = dynamic_cast<uf::Circle *>(shape.get());

    speed = 100;

    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("monstr1"));
    sprite->setTextureRect(sf::IntRect(10, 10, 40, 40));
}

void Enemy::Update(sf::Time timeElapsed) {
    Hero *hero = Game::Get()->GetMap()->GetHero();
    if (shape->Intersect(hero->GetShape())) {
        //std::cout << "GOTCHA" << std::endl;
    } else {
        setMoveDirection((hero->GetPosition() - shape->GetPosition()).normalize());
    }
    Mob::Update(timeElapsed);
}
