#include "tPoint.h"
#include <time.h>
#include <cmath>
#include <numbers>

# define M_PI           3.14159265358979323846 

float tPoint::getX()
{
	return x;
}

float tPoint::getY()
{
	return y;
}

float tPoint::getSpeed()
{
	return speed;
}

sf::Color tPoint::getColor()
{
	return color;
}

float tPoint::getAngle()
{
	return angle;
}

float tPoint::getSize()
{
	return size;
}

void tPoint::setX(float x)
{
	this->x = x;
}

void tPoint::setY(float y)
{
	this->y = y;
}

void tPoint::setSpeed(float speed)
{
	this->speed = speed;
}

void tPoint::setColor(sf::Color color)
{
	this->color = color;
}

void tPoint::setAngle(float angle)
{
	this->angle = angle;
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

void tPoint::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX < 0) {
		angle = M_PI - angle;
		newX = (newX < 0) ? 0 : widht;
	}

	if (newY > height || newY < 0) {
		angle = -angle;
		newY = (newY < 0) ? 0 : height;
	}

	x = newX;
	y = newY;
}

void tPoint::moveChaotic(float widht, float height)
{
	int numb = rand() % 10 + 1;
	if (numb < 2) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX < 0) {
		angle = M_PI - angle;
		newX = (newX < 0) ? 0 : widht;
	}

	if (newY > height || newY < 0) {
		angle = -angle;
		newY = (newY < 0) ? 0 : height;
	}

	x = newX;
	y = newY;

}