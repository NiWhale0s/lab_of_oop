#pragma once
#include "Shape.h"
class tPoint : public Shape
{
private:
	float size;

public:
	tPoint() : Shape(0, 0, 1, sf::Color(255, 255, 255), 0), size(2.0) {};
	tPoint(float xVal, float yVal, float speedVal, sf::Color colorVal, float sizeVal, float angleVal) : Shape(xVal, yVal, speedVal, colorVal, angleVal), size(sizeVal) {};
	
	float getSize();
	void setSize(float size);

	void draw(sf::RenderWindow& window) override;

};
