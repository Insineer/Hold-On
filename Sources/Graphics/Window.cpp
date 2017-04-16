#include "Window.hpp"

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "World/Map.hpp"

Window::Window() {
    renderWindow.reset(new sf::RenderWindow(sf::VideoMode(800, 600), "Hold On"));
    textures["armysheet"] = uptr<sf::Texture>(new sf::Texture());
    if (!textures["armysheet"]->loadFromFile("Textures/armysheet1.png"))
        std::cout << "Error: texture armysheet1 wasn't loaded" << std::endl;
    textures["monstr1"] = uptr<sf::Texture>(new sf::Texture());
    if (!textures["monstr1"]->loadFromFile("Textures/monstr1.png"))
        std::cout << "Error: texture monstr1 wasn't loaded" << std::endl;
}

void Window::Update() {
    sf::Event event;
    while (renderWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            renderWindow->close();
    }

    renderWindow->clear(sf::Color::Black);
    Game::Get()->GetMap()->Draw(renderWindow.get());
    renderWindow->display();
}

bool Window::IsOpen() const {
    return renderWindow->isOpen();
}

sf::Texture *Window::GetTexture(const sf::String &key) const {
    return textures.at(key).get();
}

Window::~Window() {}