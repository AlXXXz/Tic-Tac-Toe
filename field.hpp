#pragma once
#include <SFML/Graphics.hpp>

class Field : public sf::Drawable {
    sf::RectangleShape background;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 

    //sf::CircleShape circle;

    sf::RectangleShape line;
    sf::RectangleShape line2;
    sf::RectangleShape line3;
    sf::RectangleShape line4;

public:
    Field();
    void update(sf::Time elapsedTime);
};