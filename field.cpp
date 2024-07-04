#include "field.hpp"



Field::Field() : background(sf::Vector2f(400, 400)), 
    circle(20.f),
    line(sf::Vector2f(400, 5.f)),
    line2(sf::Vector2f(400, 5.f)),
    line3(sf::Vector2f(400, 5.f)),
    line4(sf::Vector2f(400, 5.f)) 
{
    background.setFillColor(sf::Color::White);
    circle.setFillColor(sf::Color::Cyan);

    line.setFillColor(sf::Color::Black);
    line.rotate(90.f);
    line.setPosition(400 / 3, 0);

    line2.rotate(90.f);
    line2.setFillColor(sf::Color::Black);
    line2.setPosition((400 / 3) * 2, 0);

    line3.setFillColor(sf::Color::Black);
    line3.setPosition(0, 400 / 3);

    line4.setFillColor(sf::Color::Black);
    line4.setPosition(0, (400 / 3) * 2);
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background, states);
    target.draw(circle, states);
    target.draw(line, states);
    target.draw(line2, states);
    target.draw(line3, states);
    target.draw(line4, states);
}

void Field::drawField() {

}

void Field::update(sf::Time elapsedTime) {
    static sf::Vector2f movement(20.f, 20.f);
    circle.move(movement * elapsedTime.asSeconds());
}