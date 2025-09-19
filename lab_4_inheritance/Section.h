#pragma once
#include "Shape.h"

class Section : public Shape
{
private:
	float size;
	float angle_line;
public:
	Section() : Shape(0,0,1, sf::Color(255, 255, 255), 0), size(6.0), angle_line(0) {}
	Section(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float sizeVal, float angle_lineVal) :
		Shape(xVal, yVal, speedVal, colorVal, angle), size(sizeVal), angle_line(angle_lineVal){}

	float getSize();
	float getAngleLine();

	void setSize(float size);
	void setAngleLine(float angle_size);
	void draw(sf::RenderWindow& window) override;
	void moveLinear(float widht, float height) override;
	void moveChaotic(float widht, float height) override;
};

