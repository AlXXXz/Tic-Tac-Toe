#include "game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game() : window(sf::VideoMode(400, 400), "Tic-Tac"), gameField() {
}
   
void Game::processEvents() {
    while (window.pollEvent(event)) {
        switch (event.type){
			case sf::Event::Closed:
				window.close();
				break;
		}
    }
}

void Game::update(sf::Time elapsedTime) {
    gameField.update(elapsedTime);
}

void Game::render() {
    window.clear();
    window.draw(gameField);
    window.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}
        render();
    }
}
