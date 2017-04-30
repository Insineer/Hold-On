#pragma once

#include <SFML/System/Clock.hpp>

#include "Useful/Memory.hpp"

class Player;
class Window;
class Map;
class State;

class Game {
private:
    static Game *instance;
    uf::uptr<Player> player;
    uf::uptr<Window> window;
    uf::uptr<Map> map;
    uf::uptr<State> state;

    sf::Clock clock;

public:
    Game();

    static Game *Get();
    Player *GetPlayer() const;
    Window *GetWindow() const;
    Map *GetMap() const;

    ~Game();
};



