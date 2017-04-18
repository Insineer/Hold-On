#include "GameProcessState.hpp"

#include <SFML/Window/Event.hpp>

#include "Game.hpp"
#include "World/Map.hpp"
#include "Graphics/Window.hpp"

GameProcessState::GameProcessState() { }

void GameProcessState::HandleEvent(sf::Event event) {

}

void GameProcessState::Update() {
    game->GetMap()->Update();
}

void GameProcessState::Draw() {
    game->GetWindow()->Update();
}
