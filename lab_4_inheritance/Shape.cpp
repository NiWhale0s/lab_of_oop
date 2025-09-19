#include "Shape.h"


float Shape::getX()
{
    return x;
}

float Shape::getY()
{
    return y;
}

float Shape::getSpeed()
{
    return speed;
}

sf::Color Shape::getColor()
{
    return color;
}

float Shape::getAngle()
{
    return angle;
}

void Shape::setX(float x)
{
    this->x = x;
}

void Shape::setY(float y)
{
    this->y = y;
}

void Shape::setSpeed(float speed)
{
    this->speed = speed;
}

void Shape::setColor(sf::Color color)
{
    this->color = color;
}

void Shape::setAngle(float angle)
{
    this->angle = angle;
}

void Shape::moveLinear(float widht, float height)
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

void Shape::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
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
