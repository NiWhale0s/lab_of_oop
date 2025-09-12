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
#include <vector>

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

    vector<tPoint> points;
    vector<Section> lines;
    vector<Circle> circles;
    vector<Ellipse> ellipses;
    vector<Rectagle> rectangles;
    vector<Rhomb> rhombs;
    vector<Triangle> triangles;

    for (int i = 0; i < 5; i++) {

        float x = static_cast<float>(rand() % WIDTH);
        float y = static_cast<float>(rand() % HEIGHT);
        float speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        float angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        float size = 1.0f + static_cast<float>(rand() % 40) / 10.0f;
        tPoint point(x, y, speed, setColorCircle(), size, angle);
        points.push_back(point);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        size = 1.0f + static_cast<float>(rand() % 40) / 1.0f;
        float angle_line = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        Section line(x, y, speed, setColorCircle(), angle, size, angle_line);
        lines.push_back(line);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        float radius = 1.0f + static_cast<float>(rand() % 60) / 1.0f;
        float outline = 1.0f + static_cast<float>(rand() % 40) / 10.0f;
        Circle circle(x, y, speed, setColorCircle(), angle, radius, outline);
        circles.push_back(circle);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        radius = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
        Ellipse ellipse(x, y, speed, setColorCircle(), angle, radius);
        ellipses.push_back(ellipse);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        float distance_x = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
        float distance_y = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
        Rectagle rectangle(x, y, speed, setColorCircle(), angle, distance_x, distance_y);
        rectangles.push_back(rectangle);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        size = 1.0f + static_cast<float>(rand() % 100) / 1.0f;
        Rhomb rhomb(x, y, speed, setColorCircle(), angle, size);
        rhombs.push_back(rhomb);

        x = static_cast<float>(rand() % WIDTH);
        y = static_cast<float>(rand() % HEIGHT);
        speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        float distance = 1.0f + static_cast<float>(rand() % 80) / 1.0f;
        Triangle triangle(x, y, speed, setColorCircle(), angle, distance);
        triangles.push_back(triangle);
    }
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

        for (int i = 0; i < 5; i++) {
            if (linearMode) {
                points[i].moveLinear(WIDTH, HEIGHT);
                lines[i].moveLinear(WIDTH, HEIGHT);
                circles[i].moveLinear(WIDTH, HEIGHT);
                ellipses[i].moveLinear(WIDTH, HEIGHT);
                rectangles[i].moveLinear(WIDTH, HEIGHT);
                rhombs[i].moveLinear(WIDTH, HEIGHT);
                triangles[i].moveLinear(WIDTH, HEIGHT);
            }
            else {
                circles[i].moveChaotic(WIDTH, HEIGHT);
                ellipses[i].moveChaotic(WIDTH, HEIGHT);
                rectangles[i].moveChaotic(WIDTH, HEIGHT);
                rhombs[i].moveChaotic(WIDTH, HEIGHT);
                lines[i].moveChaotic(WIDTH, HEIGHT);
                points[i].moveChaotic(WIDTH, HEIGHT);
                triangles[i].moveChaotic(WIDTH, HEIGHT);
            }
            circles[i].draw(window);
            ellipses[i].draw(window);
            rectangles[i].draw(window);
            rhombs[i].draw(window);
            lines[i].draw(window);
            points[i].draw(window);
            triangles[i].draw(window);

        }
        window.display();
    }
    
}

