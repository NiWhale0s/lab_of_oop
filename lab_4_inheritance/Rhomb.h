#pragma once
#include "Shape.h"
class Rhomb : public Shape
{
private:
	float size;

public:
	Rhomb() : Shape(0,0,1,sf::Color(255, 255, 255), 0), size(8.0) {}
	Rhomb(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float sizeVal) : Shape(xVal, yVal, speedVal, colorVal, angleVal), size(sizeVal) {}

	float getSize();
	void setSize(float size);
	void draw(sf::RenderWindow& window) override;
	void moveLinear(float widht, float height) override;
	void moveChaotic(float widht, float height) override;
};

