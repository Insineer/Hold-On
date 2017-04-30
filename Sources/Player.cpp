#include "Player.hpp"

#include <SFML/Window.hpp>

#include "World/Objects/Hero.hpp"

void Player::Update() {
    uf::vec2f moveVector;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        moveVector.y = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveVector.y = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveVector.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveVector.x = -1;
    moveVector.normalize();
    hero->SetMoveOrder(moveVector);
}

void Player::SetHero(Hero *hero) {
    this->hero = hero;
}

Player::~Player() {}
