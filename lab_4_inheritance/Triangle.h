#pragma once
#include "Shape.h"
class Triangle : public Shape
{
private:
	float distance;
public:
	Triangle() : Shape(0,0,1,sf::Color(255, 255, 255), 0), distance(6.0) {}
	Triangle(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float distanceVal) :
		Shape(xVal, yVal, speedVal, colorVal, angleVal), distance(distanceVal) { }

	float getDistance();
	void setDistance(float distance);
	void draw(sf::RenderWindow& window) override;
	void moveLinear(float widht, float height) override;
	void moveChaotic(float widht, float height) override;
};

