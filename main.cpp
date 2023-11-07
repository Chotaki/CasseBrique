#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace std;

int main()
{
    float time = 0;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Casse Brique" /*, sf::Style::Fullscreen*/);
    sf::Clock timer;
    vector<GameObject*>objectList;

    objectList = {
        // 0 = rectangle (w,h) | 1 = circle (r) | 2 = canon
        new GameObject(150, 200, 0, 0, 100, 1, 20, 20),
        new GameObject(400, 300, 220, 150, 0, 0, 0, 0),
        new GameObject(20, 20, 0, 0, 50, 2, 0, 0)
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

        objectList[0]->movement(time);

        for (int i = 0; i < objectList.size() ; i++) {
            if (objectList[i]->rectangleOrCircle == 0) {
                window.draw(objectList[i]->rectangleDisplay());
            }
            else if (objectList[i]->rectangleOrCircle == 1) {
                window.draw(objectList[i]->circleDisplay());
            }
            else if (objectList[i]->rectangleOrCircle == 2) {
                window.draw(objectList[i]->triangleDisplay());
            }
        }

        window.display();
        time += 0.000001;
        //time = timer.restart().asSeconds();
        cout << time << endl;
    }

    return 0;
}