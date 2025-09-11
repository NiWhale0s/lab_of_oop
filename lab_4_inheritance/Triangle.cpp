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
