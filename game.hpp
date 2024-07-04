#pragma once
#include <SFML/Graphics.hpp>
#include "field.hpp"

class Game {
    sf::RenderWindow window;
    //sf::RectangleShape background;
    sf::Event event;

    Field gameField;

    static const sf::Time TimePerFrame;

    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

public:
    Game();
    void run();
};