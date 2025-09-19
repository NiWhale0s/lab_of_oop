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

void Ellipse::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + radius * 1.5f > widht || newX - radius * 1.5f < 0) {
		angle = M_PI - angle;
		newX = (newX - radius * 1.5f < 0) ? 0 + radius * 1.5f : widht - radius * 1.5f;
	}

	if (newY + radius * 0.8f > height || newY - radius * 0.8f < 0) {
		angle = -angle;
		newY = (newY - radius * 0.8f < 0) ? 0 + radius * 0.8f : height - radius * 0.8f;
	}

	x = newX;
	y = newY;
}

void Ellipse::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + radius * 1.5f > widht || newX - radius * 1.5f < 0) {
		angle = M_PI - angle;
		newX = (newX - radius * 1.5f < 0) ? 0 + radius * 1.5f : widht - radius * 1.5f;
	}

	if (newY + radius * 0.8f > height || newY - radius * 0.8f < 0) {
		angle = -angle;
		newY = (newY - radius * 0.8f < 0) ? 0 + radius * 0.8f : height - radius * 0.8f;
	}

	x = newX;
	y = newY;
}
