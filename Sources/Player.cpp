#include "Player.hpp"

#include <SFML/Window.hpp>

#include "Game.hpp"
#include "Graphics/Window.hpp"
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

    uf::vec2f viewVector = Game::Get()->GetWindow()->GetMousePosition();
    //std::cout << viewVector << std::endl;
    viewVector -= Game::Get()->GetWindow()->GetSize() / 2;
    std::cout << uf::vec2f(sf::Mouse::getPosition()) << std::endl;
    hero->SetViewDirection(viewVector.GetAngle());
}

void Player::SetHero(Hero *hero) {
    this->hero = hero;
}

Player::~Player() {}
