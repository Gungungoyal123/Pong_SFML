#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
private:
    sf::Font font;
    sf::Text titleText;
    sf::Text highScoreText;
    sf::RectangleShape newGameButton;
    sf::Text newGameText;

public:
    Menu();
    void setHighScore(int score);
    bool isNewGameClicked(const sf::Vector2i& mousePos);
    void draw(sf::RenderWindow& window);
};

#endif
