#include "Ball.h"

Ball::Ball(float x, float y) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);

    velocityX = -300.f;
    velocityY = 300.f;
}

void Ball::update(float dt) {
    shape.move(velocityX * dt, velocityY * dt);

    if (shape.getPosition().y <= 0 || shape.getPosition().y >= 580) {
        bounceY();
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::reset(float x, float y) {
    shape.setPosition(x, y);
    velocityX = -velocityX;
}

void Ball::bounceX() {
    velocityX = -velocityX;
}

void Ball::bounceY() {
    velocityY = -velocityY;
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}
