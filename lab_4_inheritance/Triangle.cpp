#include "Triangle.h"

float Triangle::getDistance()
{
    return distance;
}

void Triangle::setDistance(float distance)
{
    this->distance = distance;
}

void Triangle::draw(sf::RenderWindow& window)
{
    sf::CircleShape triangle(distance, 3);
    triangle.setFillColor(color);
    triangle.setPosition(sf::Vector2f(x - distance, y - distance));
    window.draw(triangle);
}

void Triangle::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + distance > widht || newX - distance < 0) {
		angle = M_PI - angle;
		newX = (newX - distance < 0) ? 0 + distance : widht - distance;
	}

	if (newY + distance > height || newY - distance < 0) {
		angle = -angle;
		newY = (newY - distance < 0) ? 0 + distance : height - distance;
	}

	x = newX;
	y = newY;
}


void Triangle::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + distance > widht || newX - distance < 0) {
		angle = M_PI - angle;
		newX = (newX - distance < 0) ? 0 + distance : widht - distance;
	}

	if (newY + distance > height || newY - distance < 0) {
		angle = -angle;
		newY = (newY - distance < 0) ? 0 + distance : height - distance;
	}

	x = newX;
	y = newY;
}
