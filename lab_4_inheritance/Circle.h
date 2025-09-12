#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	float radius;
	float outline;
public:
	Circle() : Shape(0,0,1,sf::Color(255, 255, 255), 0), radius(10.0), outline(2.0) {}
	Circle(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float radiusVal, float outlineVal) :
		Shape(xVal, yVal, speedVal, colorVal, angleVal), radius(radiusVal), outline(outlineVal){}

	float getRadius();
	float getOutline();
	void setOutline(float outline);
	void setRadius(float radius);
	void draw(sf::RenderWindow& window) override;

};

