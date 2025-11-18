#include "Menu.h"
#include <iostream>

Menu::Menu()
{
    if (!font.loadFromFile("assets/font.ttf"))
    {
        std::cout << "Failed to load font\n";
    }

    titleText.setFont(font);
    titleText.setString("PONG");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(240, 50);

    // High score label (used only for vs-AI, but we always show it here)
    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setPosition(200, 150);

    // AI Button
    aiButton.setSize({200, 60});
    aiButton.setFillColor(sf::Color(80, 80, 80));
    aiButton.setPosition(220, 250);

    aiButtonText.setFont(font);
    aiButtonText.setString("Play vs AI");
    aiButtonText.setFillColor(sf::Color::White);
    aiButtonText.setCharacterSize(24);

    // center text
    auto b1 = aiButtonText.getLocalBounds();
    aiButtonText.setOrigin(b1.left + b1.width / 2, b1.top + b1.height / 2);
    aiButtonText.setPosition(aiButton.getPosition().x + 100,
                             aiButton.getPosition().y + 30);

    // PVP Button
    pvpButton.setSize({200, 60});
    pvpButton.setFillColor(sf::Color(80, 80, 80));
    pvpButton.setPosition(220, 350);

    pvpButtonText.setFont(font);
    pvpButtonText.setString("Two Players");
    pvpButtonText.setFillColor(sf::Color::White);
    pvpButtonText.setCharacterSize(24);

    // center
    auto b2 = pvpButtonText.getLocalBounds();
    pvpButtonText.setOrigin(b2.left + b2.width / 2, b2.top + b2.height / 2);
    pvpButtonText.setPosition(pvpButton.getPosition().x + 100,
                              pvpButton.getPosition().y + 30);

    // Button: make it dark so text can be light
    // newGameButton.setSize(sf::Vector2f(200, 60));
    // newGameButton.setFillColor(sf::Color(80, 80, 80));
    // newGameButton.setPosition(220, 250);

    // newGameText.setFont(font);
    // newGameText.setString("New Game");
    // newGameText.setCharacterSize(24);
    // newGameText.setFillColor(sf::Color::White);

    // // Center the text inside the button
    // sf::FloatRect textBounds = newGameText.getLocalBounds();
    // newGameText.setOrigin(textBounds.left + textBounds.width / 2.0f,
    //                       textBounds.top + textBounds.height / 2.0f);

    // newGameText.setPosition(
    //     newGameButton.getPosition().x + newGameButton.getSize().x / 2.0f,
    //     newGameButton.getPosition().y + newGameButton.getSize().y / 2.0f);
}

void Menu::setHighScore(int score)
{
    highScoreText.setString("High Score: " + std::to_string(score));
}

// bool Menu::isNewGameClicked(const sf::Vector2i &mousePos)
// {
//     return newGameButton.getGlobalBounds().contains(mousePos.x, mousePos.y);
// }

// bool Menu::isAISelected(const sf::Vector2i &pos)
// {
//     return aiButton.getGlobalBounds().contains(pos.x, pos.y);
// }

// bool Menu::isPVPSelected(const sf::Vector2i &pos)
// {
//     return pvpButton.getGlobalBounds().contains(pos.x, pos.y);
// }

bool Menu::isAISelected(const sf::Vector2i &mousePos) const
{
    return aiButton.getGlobalBounds().contains(
        static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y));
}

bool Menu::isPVPSelected(const sf::Vector2i &mousePos) const
{
    return pvpButton.getGlobalBounds().contains(
        static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y));
}

void Menu::draw(sf::RenderWindow &window)
{
    // window.draw(titleText);
    // window.draw(highScoreText);
    // window.draw(newGameButton);
    // window.draw(newGameText);

    window.draw(titleText);
    window.draw(highScoreText);
    window.draw(aiButton);
    window.draw(aiButtonText);
    window.draw(pvpButton);
    window.draw(pvpButtonText);
}
