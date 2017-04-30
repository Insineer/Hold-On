#include "GameProcessState.hpp"

#include <SFML/Window/Event.hpp>

#include "Game.hpp"
#include "World/Map.hpp"
#include "Graphics/Window.hpp"

GameProcessState::GameProcessState() { }

void GameProcessState::HandleEvent(sf::Event event) {

}

void GameProcessState::Update(sf::Time timeElapsed) {
    game->GetMap()->Update(timeElapsed);
}

void GameProcessState::Draw() {
    game->GetWindow()->Update();
}
