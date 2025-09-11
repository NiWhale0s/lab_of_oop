#include "Rhomb.h"

float Rhomb::getSize() {
	return size;
}

void Rhomb::setSize(float size) {
	this->size = size;
}

void Rhomb::draw(sf::RenderWindow& window) {
	sf::ConvexShape rhomb;

	rhomb.setPointCount(4);
	rhomb.setPoint(0, sf::Vector2f(size / 2, 0));
	rhomb.setPoint(1, sf::Vector2f(size, size / 2));
	rhomb.setPoint(2, sf::Vector2f(size / 2, size));
	rhomb.setPoint(3, sf::Vector2f(0, size / 2));

	rhomb.setPosition(sf::Vector2f(x - size, y - size));
	rhomb.setFillColor(color);
	window.draw(rhomb);
}