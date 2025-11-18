#include "Menu.h"
#include <iostream>

Menu::Menu() {
    if (!font.loadFromFile("assets/font.ttf")) {
        std::cout << "Failed to load font\n";
    }

    titleText.setFont(font);
    titleText.setString("PONG");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(240, 50);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(200, 150);

    newGameButton.setSize(sf::Vector2f(200, 60));
    newGameButton.setFillColor(sf::Color(80, 80, 80));
    newGameButton.setPosition(220, 250);

    newGameText.setFont(font);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(24);
    newGameText.setFillColor(sf::Color::White);

    // Center the text inside the button
    sf::FloatRect textBounds = newGameText.getLocalBounds();
    newGameText.setOrigin(textBounds.left + textBounds.width / 2.0f,
                          textBounds.top + textBounds.height / 2.0f);

    newGameText.setPosition(
        newGameButton.getPosition().x + newGameButton.getSize().x / 2.0f,
        newGameButton.getPosition().y + newGameButton.getSize().y / 2.0f
    );
}

void Menu::setHighScore(int score) {
    highScoreText.setString("High Score: " + std::to_string(score));
}

bool Menu::isNewGameClicked(const sf::Vector2i& mousePos) {
    return newGameButton.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(titleText);
    window.draw(highScoreText);
    window.draw(newGameButton);
    window.draw(newGameText);
}
