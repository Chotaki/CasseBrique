#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Casse Brique" /*, sf::Style::Fullscreen*/);

    vector<GameObject*>objectList;

    objectList = {
        // 0 = rectangle (w,h) | 1 = circle (r) | 2 = canon
        new GameObject(150, 200, 0, 0, 100, 1),
        new GameObject(400, 300, 220, 150, 0, 0),
        new GameObject(20, 20, 0, 0, 50, 2)
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < objectList.size() ; i++) {
            if (objectList[i]->rectangleOrCircle == 0) {
                window.draw(objectList[i]->rectangleDisplay(objectList[i]->posX, objectList[i]->posY, objectList[i]->width, objectList[i]->height));
            }
            else if (objectList[i]->rectangleOrCircle == 1) {
                window.draw(objectList[i]->circleDisplay(objectList[i]->posX, objectList[i]->posY, objectList[i]->radius));
            }
            else if (objectList[i]->rectangleOrCircle == 2) {
                window.draw(objectList[i]->canonDisplay(objectList[i]->posX, objectList[i]->posY, objectList[i]->radius));
            }
        }

        window.display();
    }

    return 0;
}