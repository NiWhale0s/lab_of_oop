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
#include <memory>

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

    vector<unique_ptr<Shape>> shapes;

    for (int i = 0; i < 3; i++) {
        shapes.push_back(make_unique<Circle>());
        shapes.push_back(make_unique<tPoint>());
        shapes.push_back(make_unique<Section>());
        shapes.push_back(make_unique<Rectagle>());
        shapes.push_back(make_unique<Ellipse>());
        shapes.push_back(make_unique<Rhomb>());
        shapes.push_back(make_unique<Triangle>());
        
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

        for (auto& shape : shapes) {
            if (linearMode) {
                shape->moveLinear(WIDTH, HEIGHT);
            }
            else {
                shape->moveChaotic(WIDTH, HEIGHT);
            }
            shape->draw(window);
        }

        
        window.display();
    }
    
}

