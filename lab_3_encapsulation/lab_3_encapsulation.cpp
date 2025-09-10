#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "tPoint.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const int HEIGHT = 1000;
const int WIDTH = 1000;
const int POINT_COUNT = 100;

sf::Color setColorCircle() {
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode({ WIDTH, HEIGHT }), "First lab OOP");
    window.setFramerateLimit(60);

    vector<tPoint> points;
    for (int i = 0; i < POINT_COUNT; i++) {
        float x = static_cast<float>(rand() % WIDTH);
        float y = static_cast<float>(rand() % HEIGHT);
        float speed = 1.0f + static_cast<float>(rand() % 30) / 10.0f;
        float angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f;
        float size = 1.0f + static_cast<float>(rand() % 40) / 10.0f;
        tPoint temp(x, y, speed, setColorCircle(), size, angle);
        points.push_back(temp);
    }

    bool linearMode = true;
    cout << "Mode: Straight-line (SPACE bar for mode change)" << std::endl;

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

        for (auto& point : points) {
            if (linearMode) {
                point.moveLinear(WIDTH, HEIGHT);
            }
            else {
                point.moveChaotic(WIDTH, HEIGHT);
            }
            point.draw(window);
        }

        window.display();
    }

    return 0;
}