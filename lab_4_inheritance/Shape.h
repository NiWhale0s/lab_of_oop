#pragma once

#include <SFML/Graphics.hpp>
# define M_PI           3.14159265358979323846 

class Shape
{
protected:
	float x, y;
	float speed;
	sf::Color color;
	float angle;

public:
	Shape(float xVal, float yVal, float speedVal, sf::Color colorVal, float angleVal) : x(xVal), y(yVal), speed(speedVal), color(colorVal), angle(angleVal) {}
	virtual ~Shape() = default;

	float getX();
	float getY();
	float getSpeed();
	sf::Color getColor();
	float getAngle();

	void setX(float x);
	void setY(float y);
	void setSpeed(float speed);
	void setColor(sf::Color color);
	void setAngle(float angle);

	void virtual moveLinear(float widht, float height);
	void virtual moveChaotic(float widht, float height);

	virtual void draw(sf::RenderWindow& window) = 0;

};

