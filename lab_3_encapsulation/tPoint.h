#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class tPoint
{
private:
	float x;
	float y;
	float speed;
	sf::Color color;
	float size;
	float angle;

public:
	tPoint() : x(0), y(0), speed(1), color(255, 255, 255), size(2.0), angle(0) {};
	tPoint(float xVal, float yVal, float speedVal, sf::Color colorVal, float sizeVal, float angleVal) : x(xVal), y(yVal), speed(speedVal),
		color(colorVal), size(sizeVal), angle(angleVal) {
	};

	float getX();
	float getY();
	float getSpeed();
	sf::Color getColor();
	float getAngle();
	float getSize();

	void setX(float x);
	void setY(float y);
	void setSpeed(float speed);
	void setColor(sf::Color color);
	void setAngle(float angle);
	void setSize(float size);

	void draw(sf::RenderWindow& window);
	void moveLinear(float widht, float height);
	void moveChaotic(float widht, float height);


};

