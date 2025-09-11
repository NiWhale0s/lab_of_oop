#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "tPoint.h"
#include "Shape.h"
#include "Rhomb.h"
#include "Rectagle.h"
#include "Circle.h"
#include "Section.h"
#include "Triangle.h"
#include "Ellipse.h"

using namespace std;

const int HEIGHT = 800;
const int WIDTH = 1200;


sf::Color setColorCircle() {
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode({ WIDTH, HEIGHT }), "Oop labs");
    window.setFramerateLimit(60);

    float x = static_cast<float>(rand() % WIDTH);
    float y = static_cast<float>(rand() % HEIGHT);
    float speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    float angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    float size = 1.0f + static_cast<float>(rand() % 40) / 10.0f;
    tPoint point(x, y, speed, setColorCircle(), size, angle);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    size = 1.0f + static_cast<float>(rand() % 40) / 1.0f;
    float angle_line = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    Section line(x, y, speed, setColorCircle(), angle, size, angle_line);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    float radius = 1.0f + static_cast<float>(rand() % 60) / 1.0f;
    float outline = 1.0f + static_cast<float>(rand() % 40) / 10.0f;
    Circle circle(x, y, speed, setColorCircle(), angle, radius, outline);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    radius = 1.0f + static_cast<float>(rand() % 260) / 1.0f;
    Ellipse ellipse(x, y, speed, setColorCircle(), angle, radius);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    float distance_x = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
    float distance_y = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
    Rectagle rectangle(x, y, speed, setColorCircle(), angle, distance_x, distance_y);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    size = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
    Rhomb rhomb(x, y, speed, setColorCircle(), angle, size);

    x = static_cast<float>(rand() % WIDTH);
    y = static_cast<float>(rand() % HEIGHT);
    speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
    angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
    float distance = 1.0f + static_cast<float>(rand() % 80) / 1.0f;
    Triangle triangle(x, y, speed, setColorCircle(), angle, distance);

    bool linearMode = true;
    cout << "Mode: Straight-line (SPACE bar for mode change)" << endl;

    while (window.isOpen()) {
        for (auto event = window.pollEvent(); event.has_value(); event = window.pollEvent()) {
            const auto& e = event.value();

            if (e.is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyEvent = e.getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->scancode == sf::Keyboard::Scan::Space) {
                    linearMode = !linearMode;
                    std::cout << "Mode: " << (linearMode ? "Linear" : "Chaotic") << std::endl;
                }
            }
        }

        window.clear(sf::Color::Black);

        if (linearMode) {
            circle.moveLinear(WIDTH, HEIGHT);
            ellipse.moveLinear(WIDTH, HEIGHT);
            rectangle.moveLinear(WIDTH, HEIGHT);
            rhomb.moveLinear(WIDTH, HEIGHT);
            line.moveLinear(WIDTH, HEIGHT);
            point.moveLinear(WIDTH, HEIGHT);
            triangle.moveLinear(WIDTH, HEIGHT);
        }
        else {
            circle.moveChaotic(WIDTH, HEIGHT);
            ellipse.moveChaotic(WIDTH, HEIGHT);
            rectangle.moveChaotic(WIDTH, HEIGHT);
            rhomb.moveChaotic(WIDTH, HEIGHT);
            line.moveChaotic(WIDTH, HEIGHT);
            point.moveChaotic(WIDTH, HEIGHT);
            triangle.moveChaotic(WIDTH, HEIGHT);
        }
        circle.draw(window);
        ellipse.draw(window);
        rectangle.draw(window);
        rhomb.draw(window);
        line.draw(window);
        point.draw(window);
        triangle.draw(window);

        window.display();
    }
    
}

