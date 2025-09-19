#pragma once
#include "Shape.h"
class Ellipse : public Shape
{
private:
	float radius;
public:
	Ellipse() : Shape(0,0,1,sf::Color(255,255,255), 0), radius(7.0) {}
	Ellipse(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float radiusVal) : Shape(xVal, yVal, speedVal, colorVal, angleVal), radius(radiusVal) {}

	float getRadius();
	void setRadius(float radius);
	void draw(sf::RenderWindow& window) override;
	void moveLinear(float widht, float height) override;
	void moveChaotic(float widht, float height) override;
};

