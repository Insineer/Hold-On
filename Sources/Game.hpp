#pragma once

#include "Useful.hpp"

class Player;
class Window;
class Map;
class State;

class Game {
private:
    static Game *instance;
    uptr<Player> player;
    uptr<Window> window;
    uptr<Map> map;
    uptr<State> state;

public:
    Game();

    static Game *Get();
    Player *GetPlayer() const;
    Window *GetWindow() const;
    Map *GetMap() const;

    ~Game();
};



