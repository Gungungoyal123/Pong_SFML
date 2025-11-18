#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape;
    float velocityX;
    float velocityY;

public:
    Ball(float x, float y);
    void update(float dt);
    void draw(sf::RenderWindow& window);
    void reset(float x, float y);
    void bounceX();
    void bounceY();
    sf::FloatRect getBounds() const;
};

#endif
