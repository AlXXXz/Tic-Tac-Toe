#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    int field[9] = { 0 };

    int height = 400;
    int width = 400;
    sf::RenderWindow window(sf::VideoMode(height, width), "title");
    sf::Event event;
    sf::RectangleShape background(sf::Vector2f(height, width));
    background.setFillColor(sf::Color::White);

    sf::RectangleShape line(sf::Vector2f(height, 5.f));
    line.setFillColor(sf::Color::Black);
    line.rotate(90.f);
    line.setPosition(width / 3, 0);

    sf::RectangleShape line2(sf::Vector2f(height, 5.f));
    line2.rotate(90.f);
    line2.setFillColor(sf::Color::Black);
    line2.setPosition((width / 3) * 2, 0);

    sf::RectangleShape line3(sf::Vector2f(width, 5.f));
    line3.setFillColor(sf::Color::Black);
    line3.setPosition(0, width / 3);

    sf::RectangleShape line4(sf::Vector2f(width, 5.f));
    line4.setFillColor(sf::Color::Black);
    line4.setPosition(0, (width / 3) * 2);

    sf::RectangleShape label(sf::Vector2f(width / 3, height / 3));
    sf::Sprite o_sprite;
    sf::Texture o_texture;

    o_texture.loadFromFile("O.png");

    sf::Vector2f targetSize(width / 3.f, height / 3.f);

    o_sprite.setTexture(o_texture);
    o_sprite.setScale(
        targetSize.x / o_sprite.getLocalBounds().width,
        targetSize.y / o_sprite.getLocalBounds().height
    );


    sf::Sprite x_sprite;
    sf::Texture x_texture;

    x_texture.loadFromFile("X.png");
    
    x_sprite.setTexture(x_texture);
    x_sprite.setScale(
        targetSize.x / x_sprite.getLocalBounds().width,
        targetSize.y / x_sprite.getLocalBounds().height
    );

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (event.mouseButton.x < width / 3 && event.mouseButton.y < height / 3) {
                    std::cout << "1\n";
                    field[0] = 1;
                }
                if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y < height / 3) {
                    std::cout << "2\n";
                    field[1] = 2;
                }
                if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y < height / 3) {
                    std::cout << "3\n";
                    field[2] = 1;
                }

                if (event.mouseButton.x < width / 3 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                    std::cout << "4\n";
                    field[3] = 1;
                }
                if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                    std::cout << "5\n";
                    field[4] = 1;
                }
                if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > width / 3 && event.mouseButton.y < (width / 3) * 2) {
                    std::cout << "6\n";
                    field[5] = 1;
                }

                if (event.mouseButton.x < width / 3 && event.mouseButton.y > (height / 3) * 2) {
                    std::cout << "7\n";
                    field[6] = 1;
                }
                if (event.mouseButton.x > width / 3&& event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                    std::cout << "8\n";
                    field[7] = 1;
                }
                if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                    std::cout << "9\n";
                    field[8] = 1;
                }
            }
        }

        window.clear();
        window.draw(background);
        window.draw(line);
        window.draw(line2);
        window.draw(line3);
        window.draw(line4);

        if (field[0] > 0) {
            o_sprite.setPosition(0, 0);
            window.draw(o_sprite);
        }

        if (field[1] == 1) {
            o_sprite.setPosition(width / 3, 0);
            window.draw(o_sprite);
        }

        if (field[1] == 2) {
            x_sprite.setPosition(width / 3, 0);
            window.draw(x_sprite);
        }

        if (field[2] > 0) {
            o_sprite.setPosition((width / 3) * 2, 0);
            window.draw(o_sprite);
        }

        if (field[3] > 0) {
            o_sprite.setPosition(0, height / 3);
            window.draw(o_sprite);
        }

        if (field[4] > 0) {
            o_sprite.setPosition(width / 3, height / 3);
            window.draw(o_sprite);
        }

        if (field[5] > 0) {
            o_sprite.setPosition((width / 3) * 2, height / 3);
            window.draw(o_sprite);
        }

        if (field[6] > 0) {
            o_sprite.setPosition(0, (height / 3) * 2);
            window.draw(o_sprite);
        }

        if (field[7] > 0) {
            o_sprite.setPosition(width / 3, (height / 3) * 2);
            window.draw(o_sprite);
        }

        if (field[8] > 0) {
            o_sprite.setPosition((width / 3) * 2, (height / 3) * 2);
            window.draw(o_sprite);
        }

        window.display();
    }

    return 0;
}