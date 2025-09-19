#pragma once
#include "Shape.h"
class Rectagle : public Shape
{
private:
	float distance_x;
	float distance_y;
public:
	Rectagle() : Shape(0, 0, 1, sf::Color(255, 255, 255), 0), distance_x(10.0), distance_y(6.0){}
	Rectagle(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal, float distance_xVal, float distance_yVal) :
		Shape(xVal, yVal, speedVal, colorVal, angleVal), distance_x(distance_xVal), distance_y(distance_yVal) {}

	float getDistanceX();
	float getDistanceY();

	void setDistanceX(float distance_x);
	void setDistanceY(float distance_y);
	void draw(sf::RenderWindow& window) override;
	void moveLinear(float widht, float height) override;
	void moveChaotic(float widht, float height) override;
};

