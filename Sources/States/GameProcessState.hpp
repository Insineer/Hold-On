#pragma once

#include "State.hpp"

class GameProcessState : public State {
public:
    GameProcessState();
    void HandleEvent(sf::Event) final;
    void Update(sf::Time) final;
    void Draw() final;
};


