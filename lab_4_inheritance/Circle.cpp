#include "Circle.h"

# define M_PI           3.14159265358979323846 

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

void Circle::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + radius + outline > widht || newX - radius - outline  < 0) {
		angle = M_PI - angle;
		newX = (newX - radius - outline < 0) ? 0 + radius + outline  : widht - radius - outline;
	}

	if (newY + radius + outline > height || newY - radius - outline < 0) {
		angle = -angle;
		newY = (newY - radius - outline < 0) ? 0 + radius + outline : height - radius - outline;
	}

	x = newX;
	y = newY;
}

void Circle::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + radius + outline > widht || newX - radius - outline < 0) {
		angle = M_PI - angle;
		newX = (newX - radius - outline < 0) ? 0 + radius + outline : widht - radius - outline;
	}

	if (newY + radius + outline > height || newY - radius - outline < 0) {
		angle = -angle;
		newY = (newY - radius - outline < 0) ? 0 + radius + outline : height - radius - outline;
	}

	x = newX;
	y = newY;
}
