#pragma once

#include <map>
#include <SFML/System/String.hpp>

#include "Useful/Memory.hpp"
#include "Useful/Geometry/Vec2f.hpp"

namespace sf {
    class RenderWindow;
    class Texture;
    class Event;
}

class Window {
private:
    uf::uptr<sf::RenderWindow> renderWindow;
    std::map<sf::String, uf::uptr<sf::Texture>> textures;

public:
    Window();
    void Update();

    bool PollEvent(sf::Event &event);
    void Close();

    bool IsOpen() const;
    sf::Texture *GetTexture(const sf::String &key) const;
    uf::vec2f GetSize() const;
    // Mouse position relative to down-left window corner
    uf::vec2f GetMousePosition() const;

    ~Window();
};
