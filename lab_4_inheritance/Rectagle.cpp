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
