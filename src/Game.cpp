#include "Game.h"
#include <fstream>
#include <iostream>

Game::Game() 
    : window(sf::VideoMode(640, 600), "Pong", sf::Style::Titlebar | sf::Style::Close),
      state(GameState::MENU),
      leftPaddle(30, 250),
      rightPaddle(590, 250),
      ball(320, 300),
      leftScore(0),
      rightScore(0),
      highScore(0)
{
    window.setFramerateLimit(60);

    if (!font.loadFromFile("assets/font.ttf")) {
        std::cout << "Failed to load font\n";
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(280, 20);
    scoreText.setString(std::to_string(leftScore) + " : " + std::to_string(rightScore));


    loadHighScore();
    menu.setHighScore(highScore);
}


void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (state == GameState::MENU && event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (menu.isNewGameClicked(mousePos)) {
                leftScore = 0;
                rightScore = 0;
                ball.reset(320, 300);
                state = GameState::PLAYING;
            }
        }
    }
}

void Game::update(float dt) {
    if (state == GameState::PLAYING) {

        // Paddle movement: W/S and UP/DOWN
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            leftPaddle.moveUp(dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            leftPaddle.moveDown(dt);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            rightPaddle.moveUp(dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            rightPaddle.moveDown(dt);

        // Update ball
        ball.update(dt);

        // Collision with paddles
        if (ball.getBounds().intersects(leftPaddle.getBounds()))
            ball.bounceX();
        if (ball.getBounds().intersects(rightPaddle.getBounds()))
            ball.bounceX();

        // Scoring logic
        if (ball.getBounds().left < 0) {
            rightScore++;
            ball.reset(320, 300);
        }

        if (ball.getBounds().left > 640) {
            leftScore++;
            ball.reset(320, 300);
        }

        // Update score text
        scoreText.setString(
            std::to_string(leftScore) + " : " + std::to_string(rightScore)
        );

        // End game condition
        if (leftScore == 10 || rightScore == 10) {
            int finalScore = std::max(leftScore, rightScore);

            if (finalScore > highScore) {
                highScore = finalScore;
                saveHighScore();
            }

            menu.setHighScore(highScore);
            state = GameState::MENU;
        }
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    if (state == GameState::MENU) {
        menu.draw(window);
    }
    else if (state == GameState::PLAYING) {
        leftPaddle.draw(window);
        rightPaddle.draw(window);
        ball.draw(window);
        window.draw(scoreText);
    }

    window.display();
}

void Game::loadHighScore() {
    std::ifstream file("highscore.txt");
    highScore = 0;

    if (file)
        file >> highScore;
}

void Game::saveHighScore() {
    std::ofstream file("highscore.txt");
    file << highScore;
}
