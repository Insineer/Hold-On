#pragma once

class Game;

namespace sf {
    class Event;
}

class State {
protected:
    Game *game;
public:
    State();
    virtual void HandleEvent(sf::Event) = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};


