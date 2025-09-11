#include "tPoint.h"

float tPoint::getSize()
{
	return size;
}

void tPoint::setSize(float size)
{
	this->size = size;
}

void tPoint::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(size);
	circle.setFillColor(color);
	circle.setPosition(sf::Vector2f(x - size, y - size));
	window.draw(circle);
}
