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

void Rhomb::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX - size < 0) {
		angle = M_PI - angle;
		newX = (newX - size < 0) ? 0 + size : widht;
	}

	if (newY > height || newY - size < 0) {
		angle = -angle;
		newY = (newY - size < 0) ? 0 + size : height;
	}

	x = newX;
	y = newY;
}

void Rhomb::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX - size < 0) {
		angle = M_PI - angle;
		newX = (newX - size < 0) ? 0 + size : widht;
	}

	if (newY > height || newY - size < 0) {
		angle = -angle;
		newY = (newY - size < 0) ? 0 + size : height;
	}

	x = newX;
	y = newY;
}
