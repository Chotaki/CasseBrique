#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
//#include "Brick.h"

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

    bool fire = true;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Casse Brique" /*, sf::Style::Fullscreen*/);
    sf::Clock timer;
    vector<GameObject*>objectList;

    float windowSizeX = window.getSize().x;
    float windowSizeY = window.getSize().y;

    objectList = {
        // 0 = rectangle (w,h) | 1 = circle (r) | 2 = triangle
        // for direction ++ = bottom right | +- = bottom left | -+ = top right | -- = top left
        new GameObject(windowSizeX / 2 - 10 , windowSizeY - 110, 0, 0, 10, 1,0),
        new GameObject(windowSizeX/2, windowSizeY-100, 0, 0, 50, 2,0),
		new GameObject(75.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(155.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(235.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(315.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(395.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(475.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(555.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(635.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(715.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(795.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(875.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(955.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(1035.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(1115.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(1195.f, 100.f, 75, 40, 0, 0,3),
		new GameObject(75.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(155.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(235.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(315.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(395.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(475.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(555.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(635.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(715.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(795.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(875.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(955.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(1035.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(1115.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(1195.f, 145.f, 75, 40, 0, 0,3),
		new GameObject(75.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(155.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(235.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(315.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(395.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(475.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(555.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(635.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(715.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(795.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(875.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(955.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(1035.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(1115.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(1195.f, 190.f, 75, 40, 0, 0,3),
		new GameObject(75.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(155.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(235.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(315.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(395.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(475.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(555.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(635.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(715.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(795.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(875.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(955.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(1035.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(1115.f, 235.f, 75, 40, 0, 0,3),
		new GameObject(1195.f, 235.f, 75, 40, 0, 0,3),
    };


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (fire){
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							objectList[0]->shoot(objectList, sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
							window.draw(*objectList[0]->circleDisplay());
                            fire = false;
						}
                    }
                    break;

                default:
                    break;
            }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        window.clear();

		if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == true) {
			objectList[0]->movement(time, windowSizeX, windowSizeY);
			fire = true;
		}
		if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == false) {
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