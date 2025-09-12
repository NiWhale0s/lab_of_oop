#include "Section.h"


float Section::getAngleLine()
{
	return angle_line;
}

float Section::getSize()
{
	return size;
}

void Section::setSize(float size)
{
	this->size = size;
}

void Section::setAngleLine(float angle_size)
{
	this->angle_line = angle_size;
}

void Section::draw(sf::RenderWindow& window) {
	sf::VertexArray line(sf::PrimitiveType::LineStrip, 2);
	line[0].position = sf::Vector2f(x - size, y - size);
	line[1].position = sf::Vector2f(x,y);
	line[0].color = color;
	line[1].color = color;

	window.draw(line);
}