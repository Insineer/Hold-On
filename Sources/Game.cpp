#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Graphics/Window.hpp"
#include "World/Map.hpp"
#include "States/GameProcessState.hpp"

Game::Game() {
    sf::Time minTickTime = sf::seconds(1.f / 60);
    sf::Time timeElapsed;

    if (instance) {
        std::cout << "Error: Attempt to create second Game instance!" << std::endl;
        exit(1);
    }
    instance = this;
    player.reset(new Player());
    window.reset(new Window());
    map.reset(new Map());
    state.reset(new GameProcessState());

    while(window->IsOpen()) {
        timeElapsed = clock.restart();
        if (timeElapsed < minTickTime) {
            sf::sleep(minTickTime - timeElapsed);
            timeElapsed = minTickTime;
        }

        sf::Event event;
        while (window->PollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->Close();
            state->HandleEvent(event);
        }
        state->Update(timeElapsed);
        state->Draw();
    }
}

Game *Game::Get() { return instance; }
Player *Game::GetPlayer() const { return player.get(); }
Window *Game::GetWindow() const { return window.get(); }
Map *Game::GetMap() const { return map.get(); }

Game::~Game() {}

Game *Game::instance = nullptr;
