#include "Player.hpp"

#include "World/Objects/Hero.hpp"

void Player::SetHero(Hero *hero) {
    this->hero = hero;
}

Player::~Player() {}
