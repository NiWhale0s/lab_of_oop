#include "Circle.h"

float Circle::getRadius()
{
	return radius;
}

float Circle::getOutline()
{
	return outline;
}

void Circle::setOutline(float outline)
{
	this->outline = outline;
}

void Circle::setRadius(float radius)
{
	this->radius = radius;
}

void Circle::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(color);
	circle.setOutlineThickness(outline);
	circle.setPosition(sf::Vector2f(x - radius, y - radius));
	window.draw(circle);
}
