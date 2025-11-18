#include "Paddle.h"

Paddle::Paddle(float x, float y) {
    shape.setSize(sf::Vector2f(20, 100));
    shape.setFillColor(sf::Color::White);
    shape.setPosition(x, y);
    speed = 300.f;
}

void Paddle::moveUp(float dt) {
    if (shape.getPosition().y > 0)
        shape.move(0, -speed * dt);
}

void Paddle::moveDown(float dt) {
    if (shape.getPosition().y + shape.getSize().y < 600)
        shape.move(0, speed * dt);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}
