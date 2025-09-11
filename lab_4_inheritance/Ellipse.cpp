#include "Ellipse.h"

float Ellipse::getRadius() {
	return radius;
}

void Ellipse::setRadius(float radius) {
	this->radius = radius;
}

void Ellipse::draw(sf::RenderWindow& window) {
	sf::CircleShape ellipse(radius);
	ellipse.setScale(sf::Vector2f(1.5f, 0.8f));
	ellipse.setFillColor(color);
	ellipse.setPosition(sf::Vector2f(x - radius, y - radius));
	window.draw(ellipse);
}