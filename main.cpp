#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace std;

int main()
{
    /*
    règles pour les pointeurs

    int i = 0;

    int* pi = &i;
    *pi = 7;

    int& ri = *pi;
    */

    float time = 0;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Casse Brique" /*, sf::Style::Fullscreen*/);
    sf::Clock timer;
    vector<GameObject*>objectList;

    float windowSizeX = window.getSize().x;
    float windowSizeY = window.getSize().y;

    objectList = {
        // 0 = rectangle (w,h) | 1 = circle (r) | 2 = triangle
        // for direction ++ = bottom right | +- = bottom left | -+ = top right | -- = top left
        new GameObject(100.f, 200.f, 0, 0, 50, 1, 0, 10),
        new GameObject(400.f, 500.f, 220, 150, 0, 0, 0, 0),
        new GameObject(windowSizeX/2, windowSizeY-100, 0, 0, 50, 2, 0, 0)
    };


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        //cout << mousePosition.x << " " << mousePosition.y << endl;

        window.clear();

        if (objectList[0]->isColliding(objectList) == false) {
            objectList[0]->movement(time, windowSizeX, windowSizeY);
        }

        for (int i = 0; i < objectList.size() ; i++) {
            if (objectList[i]->shapeType == 0) {
                window.draw(*objectList[i]->rectangleDisplay());
            }
            else if (objectList[i]->shapeType == 1) {
                window.draw(*objectList[i]->circleDisplay());
            }
            else if (objectList[i]->shapeType == 2) {
                window.draw(*objectList[i]->triangleDisplay(mousePosition, windowSizeX, windowSizeY));

				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(mousePosition.x, mousePosition.y)),
					sf::Vertex(sf::Vector2f(objectList[i]->posX, objectList[i]->posY))
				};

				window.draw(line, 2, sf::Lines);
            }
        }

        window.display();
        time = timer.restart().asSeconds();
    }

    return 0;
}