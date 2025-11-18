#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Paddle.h"
#include "Ball.h"

enum class GameState {
    MENU,
    PLAYING,
    GAME_OVER
};

class Game {
private:
    sf::RenderWindow window;
    GameState state;

    Menu menu;
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;

    int leftScore;
    int rightScore;
    int highScore;
    sf::Font font;
    sf::Text scoreText;

public:
    Game();
    void run();

private:
    void processEvents();
    void update(float dt);
    void render();

    void loadHighScore();
    void saveHighScore();
};

#endif
