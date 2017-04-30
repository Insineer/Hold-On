#include "Map.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Player.hpp"
#include "World/Objects/Hero.hpp"
#include "World/Objects/Enemy.hpp"

Map::Map() {
    size = uf::vec2f(1000, 1000);
    hero = new Hero();
    hero->SetPosition(630, 620);
    Game::Get()->GetPlayer()->SetHero(hero);
    objects.push_back(uf::uptr<Object>(hero));

    Enemy *enemy = new Enemy;
    enemy->SetPosition(0, 0);
    objects.push_back(uf::uptr<Object>(enemy));
}

void Map::Update(sf::Time timeElapsed) {
    for (auto &obj : objects)
        obj->Update(timeElapsed);
}

void Map::Draw(sf::RenderTarget *target) {
    target->clear(sf::Color::White);

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Black);
    rect.setSize(sf::Vector2f(1, target->getSize().y));
    int x0 = ((int(hero->GetPosition().x - target->getSize().x / 2) / 100 + 1) * 100);
    x0 = int(x0 - hero->GetPosition().x + target->getSize().x / 2);

    for (int x = x0; x < hero->GetPosition().x + target->getSize().x / 2; x += 100) {
        rect.setPosition(x, 0);
        target->draw(rect);
    }

    rect.setSize(sf::Vector2f(target->getSize().x, 1));
    int y0 = ((int(hero->GetPosition().y - target->getSize().y / 2) / 100 + 1) * 100);
    y0 = int(y0 - hero->GetPosition().y + target->getSize().y / 2);

    for (int y = y0; y < hero->GetPosition().y + target->getSize().y / 2; y += 100) {
        rect.setPosition(0, y);
        target->draw(rect);
    }

    for (auto &obj : objects)
        if (obj->GetPosition().x >= hero->GetPosition().x - target->getSize().x &&
            obj->GetPosition().x <  hero->GetPosition().x + target->getSize().x &&
            obj->GetPosition().y >= hero->GetPosition().y - target->getSize().y &&
            obj->GetPosition().y <  hero->GetPosition().y + target->getSize().y)
            obj->Draw(target, obj->GetPosition() - (hero->GetPosition() - uf::vec2f(target->getSize()) / 2));
}

Hero *Map::GetHero() const {
    return hero;
}

Map::~Map() {}