#include "Rectagle.h"

float Rectagle::getDistanceX()
{
    return distance_x;
}

float Rectagle::getDistanceY()
{
    return distance_y;
}

void Rectagle::setDistanceX(float distance_x)
{
    this->distance_x = distance_x;
}

void Rectagle::setDistanceY(float distance_y)
{
    this->distance_y = distance_y;
}

void Rectagle::draw(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(distance_x,distance_y));
    rectangle.setPosition(sf::Vector2f(x - distance_x, y - distance_y));
    rectangle.setFillColor(color);
    window.draw(rectangle);
}

void Rectagle::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX - distance_x < 0) {
		angle = M_PI - angle;
		newX = (newX - distance_x < 0) ? 0+distance_x : widht;
	}

	if (newY > height || newY - distance_y < 0) {
		angle = -angle;
		newY = (newY - distance_y < 0) ? 0 + distance_y : height;
	}

	x = newX;
	y = newY;
}

void Rectagle::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX > widht || newX - distance_x < 0) {
		angle = M_PI - angle;
		newX = (newX - distance_x < 0) ? 0 + distance_x : widht;
	}

	if (newY > height || newY - distance_y < 0) {
		angle = -angle;
		newY = (newY - distance_y < 0) ? 0 + distance_y : height;
	}

	x = newX;
	y = newY;
}
