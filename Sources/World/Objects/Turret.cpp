#include "Turret.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
#include "World/Map.hpp"
#include "Useful/Math.hpp"
#include "Useful/Geometry/Shape/Rectangle.hpp"
#include "Enemy.hpp"

#define EPS 0.01

Turret::Turret(float defenseRadius) : defenseRadius(defenseRadius) {
    shape.reset(new uf::Rectangle(180, 135));
    shapeRectangle = dynamic_cast<uf::Rectangle *>(shape.get());

    rotationSpeed = 0.01;

    sprite.reset(new sf::Sprite);
    sprite->setTexture(*Game::Get()->GetWindow()->GetTexture("armysheet"));
    sprite->setTextureRect(sf::IntRect(20, 15, 180, 135));
    sprite->setOrigin(uf::vec2f(sprite->getTextureRect().width / 2, sprite->getTextureRect().height / 2));

    sprite->setColor(sf::Color(255, 255, 255, 128));
    active = false;
}

void Turret::Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const {
    sprite->setPosition(targetCoord);
    sprite->setRotation(-float(shape->GetRotation() * 180 / M_PI));

    target->draw(*sprite);
}

void Turret::Update(sf::Time timeElapsed) {
    Enemy *enemy = Game::Get()->GetMap()->GetEnemy();

    if (active) {
        auto diff = enemy->GetPosition() - GetPosition();
        float delta = float((shape->GetRotation() + diff.GetAngle()) / (2 * M_PI));
        delta = std::round(delta) - delta;
        if (uf::length(diff) < defenseRadius + shapeRectangle->GetSize().x / 2) {
            if (delta > EPS)
                shape->Rotate(rotationSpeed);
            else if (delta < -EPS)
                shape->Rotate(-rotationSpeed);
            else
                std::cout << "Attacking enemy" << std::endl;
        }
    }
}

void Turret::Set() {
    sprite->setColor(sf::Color(255, 255, 255, 255));
    active = true;
}