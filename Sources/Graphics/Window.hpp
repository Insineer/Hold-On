#pragma once

#include <map>
#include <SFML/System/String.hpp>

#include "Useful.hpp"

namespace sf {
    class RenderWindow;
    class Texture;
}

class Window {
private:
    uptr<sf::RenderWindow> renderWindow;
    std::map<sf::String, uptr<sf::Texture>> textures;

public:
    Window();
    void Update();

    bool IsOpen() const;
    sf::Texture *GetTexture(const sf::String &key) const;

    ~Window();
};
