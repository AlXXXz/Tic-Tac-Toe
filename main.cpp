#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Переменные игровой логики
    int field[9] = { 0 }; // Представление игрового поля в виде массива
    unsigned height = 400; // Высота игрового поля
    unsigned width = 400; // Ширина игрового поля
    char sign = 0; // За какой знак будет играть игрок
    // 1 - X, 2 - 0
    char whichTurn = 0;
    // 1 - X, 2 - 0

    float cellHeight = height / 3; // Высота клетки и знака
    float cellWidth = width / 3; // Ширина клетки и знака

    // Переменные SFML
    sf::RenderWindow window(sf::VideoMode(width, height), "Tic-tac-toe");
    sf::Event event;

    // Задний фон (белый цвет)
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::White);

    // Текстуры знаков
    sf::Texture xTexture;
    sf::Texture oTexture;

    // Спрайты знаков
    sf::Sprite xSprite;
    sf::Sprite oSprite;

    xTexture.loadFromFile("X.png");
    oTexture.loadFromFile("O.png");

    xSprite.setTexture(xTexture);
    oSprite.setTexture(oTexture);

    // Установка размера знаков
    xSprite.setScale(
        cellWidth / xSprite.getLocalBounds().width,
        cellHeight / xSprite.getLocalBounds().height
    );

    oSprite.setScale(
        cellWidth / oSprite.getLocalBounds().width,
        cellHeight / oSprite.getLocalBounds().height
    );

    // Расположение иконок выбора знака 
    xSprite.setPosition(width / 8, cellHeight);
    oSprite.setPosition((width / 8) * 4, cellHeight);

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

    // Главный игровой цикл
    while (window.isOpen()) {
        // Цикл обработки событий

        while (window.pollEvent(event)) {
            // Зыкрытие игры
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Выбор знака игроком
                if (sign == 0) {
                    if (event.mouseButton.x >= width / 8 && event.mouseButton.x <= (width / 8) + cellWidth && event.mouseButton.y >= cellHeight && event.mouseButton.y <= cellHeight + cellHeight) {
                        std::cout << "X\n";
                        sign = 1;
                        whichTurn = 1;
                    }

                    if (event.mouseButton.x >= (width / 8) * 4 && event.mouseButton.x <= (width / 8) * 4 + cellWidth && event.mouseButton.y >= cellHeight && event.mouseButton.y <= cellHeight + cellHeight) {
                        std::cout << "O\n";
                        sign = 2;
                        whichTurn = 2;
                    }
                } else if (sign == 1) { // Если знак выбран
                    if (event.mouseButton.x < width / 3 && event.mouseButton.y < height / 3) {
                        if (field[0] == 0) {
                            field[0] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y < height / 3) {
                        if (field[1] == 0) {
                            field[1] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y < height / 3) {
                        if (field[2] == 0) {
                            field[2] = 1;
                            sign = 2;
                        }
                    }

                    if (event.mouseButton.x < width / 3 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                        if (field[3] == 0) {
                            field[3] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                        if (field[4] == 0) {
                            field[4] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > width / 3 && event.mouseButton.y < (width / 3) * 2) {
                        if (field[5] == 0) {
                            field[5] = 1;
                            sign = 2;
                        }
                    }

                    if (event.mouseButton.x < width / 3 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[6] == 0) {
                            field[6] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > width / 3&& event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[7] == 0) {
                            field[7] = 1;
                            sign = 2;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[8] == 0) {
                            field[8] = 1;
                            sign = 2;
                        }
                    }
                } else if (sign == 2) { // Если знак выбран
                    if (event.mouseButton.x < width / 3 && event.mouseButton.y < height / 3) {
                        if (field[0] == 0) {
                            field[0] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y < height / 3) {
                        if (field[1] == 0) {
                            field[1] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y < height / 3) {
                        if (field[2] == 0) {
                            field[2] = 2;
                            sign = 1;
                        }
                    }

                    if (event.mouseButton.x < width / 3 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                        if (field[3] == 0) {
                            field[3] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
                        if (field[4] == 0) {
                            field[4] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > width / 3 && event.mouseButton.y < (width / 3) * 2) {
                        if (field[5] == 0) {
                            field[5] = 2;
                            sign = 1;
                        }
                    }

                    if (event.mouseButton.x < width / 3 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[6] == 0) {
                            field[6] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > width / 3&& event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[7] == 0) {
                            field[7] = 2;
                            sign = 1;
                        }
                    }
                    if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
                        if (field[8] == 0) {
                            field[8] = 2;
                            sign = 1;
                        }
                    }
                }
            }
        }
        window.clear();
        window.draw(background);

        if (sign == 0) {
            window.draw(xSprite);
            window.draw(oSprite);
        } else {
            window.draw(line);
            window.draw(line2);
            window.draw(line3);
            window.draw(line4);

            if (field[0] == 1) {
                xSprite.setPosition(0, 0);
                window.draw(xSprite);
            }

            if (field[1] == 1) {
                xSprite.setPosition(width / 3, 0);
                window.draw(xSprite);
            }

            if (field[2] == 1) {
                xSprite.setPosition((width / 3) * 2, 0);
                window.draw(xSprite);
            }

            if (field[3] == 1) {
                xSprite.setPosition(0, height / 3);
                window.draw(xSprite);
            }

            if (field[4] == 1) {
                xSprite.setPosition(width / 3, height / 3);
                window.draw(xSprite);
            }

            if (field[5] == 1) {
                xSprite.setPosition((width / 3) * 2, height / 3);
                window.draw(xSprite);
            }

            if (field[6] == 1) {
                xSprite.setPosition(0, (height / 3) * 2);
                window.draw(xSprite);
            }

            if (field[7] == 1) {
                xSprite.setPosition(width / 3, (height / 3) * 2);
                window.draw(xSprite);
            }

            if (field[8] == 1) {
                xSprite.setPosition((width / 3) * 2, (height / 3) * 2);
                window.draw(xSprite);
            }

            

            if (field[0] == 2) {
                oSprite.setPosition(0, 0);
                window.draw(oSprite);
            }

            if (field[1] == 2) {
                oSprite.setPosition(width / 3, 0);
                window.draw(oSprite);
            }

            if (field[2] == 2) {
                oSprite.setPosition((width / 3) * 2, 0);
                window.draw(oSprite);
            }

            if (field[3] == 2) {
                oSprite.setPosition(0, height / 3);
                window.draw(oSprite);
            }

            if (field[4] == 2) {
                oSprite.setPosition(width / 3, height / 3);
                window.draw(oSprite);
            }

            if (field[5] == 2) {
                oSprite.setPosition((width / 3) * 2, height / 3);
                window.draw(oSprite);
            }

            if (field[6] == 2) {
                oSprite.setPosition(0, (height / 3) * 2);
                window.draw(oSprite);
            }

            if (field[7] == 2) {
                oSprite.setPosition(width / 3, (height / 3) * 2);
                window.draw(oSprite);
            }

            if (field[8] == 2) {
                oSprite.setPosition((width / 3) * 2, (height / 3) * 2);
                window.draw(oSprite);
            }
        }

        window.display();
    }
    
    return 0;
}

// int main() {
//     int field[9] = { 0 };

//     int height = 400;
//     int width = 400;
//     sf::RenderWindow window(sf::VideoMode(height, width), "title");
//     sf::Event event;
//     sf::RectangleShape background(sf::Vector2f(height, width));
//     background.setFillColor(sf::Color::White);

//     sf::RectangleShape line(sf::Vector2f(height, 5.f));
//     line.setFillColor(sf::Color::Black);
//     line.rotate(90.f);
//     line.setPosition(width / 3, 0);

//     sf::RectangleShape line2(sf::Vector2f(height, 5.f));
//     line2.rotate(90.f);
//     line2.setFillColor(sf::Color::Black);
//     line2.setPosition((width / 3) * 2, 0);

//     sf::RectangleShape line3(sf::Vector2f(width, 5.f));
//     line3.setFillColor(sf::Color::Black);
//     line3.setPosition(0, width / 3);

//     sf::RectangleShape line4(sf::Vector2f(width, 5.f));
//     line4.setFillColor(sf::Color::Black);
//     line4.setPosition(0, (width / 3) * 2);

//     sf::RectangleShape label(sf::Vector2f(width / 3, height / 3));
//     sf::Sprite o_sprite;
//     sf::Texture o_texture;

//     o_texture.loadFromFile("O.png");

//     sf::Vector2f targetSize(width / 3.f, height / 3.f);

//     o_sprite.setTexture(o_texture);
//     o_sprite.setScale(
//         targetSize.x / o_sprite.getLocalBounds().width,
//         targetSize.y / o_sprite.getLocalBounds().height
//     );


//     sf::Sprite x_sprite;
//     sf::Texture x_texture;

//     x_texture.loadFromFile("X.png");
    
//     x_sprite.setTexture(x_texture);
//     x_sprite.setScale(
//         targetSize.x / x_sprite.getLocalBounds().width,
//         targetSize.y / x_sprite.getLocalBounds().height
//     );

//     while (window.isOpen()) {
//         while (window.pollEvent(event)) {
//             if(event.type == sf::Event::Closed) window.close();

//             if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                 if (event.mouseButton.x < width / 3 && event.mouseButton.y < height / 3) {
//                     std::cout << "1\n";
//                     field[0] = 1;
//                 }
//                 if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y < height / 3) {
//                     std::cout << "2\n";
//                     field[1] = 2;
//                 }
//                 if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y < height / 3) {
//                     std::cout << "3\n";
//                     field[2] = 1;
//                 }

//                 if (event.mouseButton.x < width / 3 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
//                     std::cout << "4\n";
//                     field[3] = 1;
//                 }
//                 if (event.mouseButton.x > width / 3 && event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > height / 3 && event.mouseButton.y < (height / 3) * 2) {
//                     std::cout << "5\n";
//                     field[4] = 1;
//                 }
//                 if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > width / 3 && event.mouseButton.y < (width / 3) * 2) {
//                     std::cout << "6\n";
//                     field[5] = 1;
//                 }

//                 if (event.mouseButton.x < width / 3 && event.mouseButton.y > (height / 3) * 2) {
//                     std::cout << "7\n";
//                     field[6] = 1;
//                 }
//                 if (event.mouseButton.x > width / 3&& event.mouseButton.x < (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
//                     std::cout << "8\n";
//                     field[7] = 1;
//                 }
//                 if (event.mouseButton.x > (width / 3) * 2 && event.mouseButton.y > (height / 3) * 2) {
//                     std::cout << "9\n";
//                     field[8] = 1;
//                 }
//             }
//         }

//         window.clear();
//         window.draw(background);
//         window.draw(line);
//         window.draw(line2);
//         window.draw(line3);
//         window.draw(line4);

//         if (field[0] > 0) {
//             o_sprite.setPosition(0, 0);
//             window.draw(o_sprite);
//         }

//         if (field[1] == 1) {
//             o_sprite.setPosition(width / 3, 0);
//             window.draw(o_sprite);
//         }

//         if (field[1] == 2) {
//             x_sprite.setPosition(width / 3, 0);
//             window.draw(x_sprite);
//         }

//         if (field[2] > 0) {
//             o_sprite.setPosition((width / 3) * 2, 0);
//             window.draw(o_sprite);
//         }

//         if (field[3] > 0) {
//             o_sprite.setPosition(0, height / 3);
//             window.draw(o_sprite);
//         }

//         if (field[4] > 0) {
//             o_sprite.setPosition(width / 3, height / 3);
//             window.draw(o_sprite);
//         }

//         if (field[5] > 0) {
//             o_sprite.setPosition((width / 3) * 2, height / 3);
//             window.draw(o_sprite);
//         }

//         if (field[6] > 0) {
//             o_sprite.setPosition(0, (height / 3) * 2);
//             window.draw(o_sprite);
//         }

//         if (field[7] > 0) {
//             o_sprite.setPosition(width / 3, (height / 3) * 2);
//             window.draw(o_sprite);
//         }

//         if (field[8] > 0) {
//             o_sprite.setPosition((width / 3) * 2, (height / 3) * 2);
//             window.draw(o_sprite);
//         }

//         window.display();
//     }

//     return 0;
// }