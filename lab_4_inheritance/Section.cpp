#include "Section.h"

# define M_PI           3.14159265358979323846 


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

void Section::moveLinear(float widht, float height)
{
	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + size * cos(angle) > widht || newX + size * cos(angle) < 0) {
		angle = M_PI - angle;
		newX = (newX - size * cos(angle) < 0) ? 0 + size : widht - size;
	}

	if (newY + size * sin(angle) > height || newY + size * sin(angle) < 0) {
		angle = -angle;
		newY = (newY - size * sin(angle) < 0) ? 0 + size : height - size ;
	}

	x = newX;
	y = newY;
}

void Section::moveChaotic(float widht, float height)
{
	int numb = rand() % 100 + 1;
	if (numb < 6) {
		angle = (rand() % 360) * M_PI / 180.0f;
	}

	float newX = x + speed * cos(angle);
	float newY = y + speed * sin(angle);

	if (newX + size * cos(angle) > widht || newX + size * cos(angle) < 0) {
		angle = M_PI  - angle;
		newX = (newX - size * cos(angle) < 0) ? 0 + size : widht - size;
	}

	if (newY + size * sin(angle) > height || newY + size * sin(angle) < 0) {
		angle = -angle;
		newY = (newY - size * sin(angle) < 0) ? 0 + size : height - size;
	}

	x = newX;
	y = newY;
}
