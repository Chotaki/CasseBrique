#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "GameObject.h"
//#include "Brick.h"

using namespace std;

vector<GameObject*> initialisationList() {
	vector<GameObject*>objectList;

	objectList = {
		// 0 = rectangle (w,h) | 1 = circle (r) | 2 = cannon
		// for direction ++ = bottom right | +- = bottom left | -+ = top right | -- = top left
		new GameObject(1366 / 2 - 10 , 768 - 110, 0, 0, 10, 1,0,true),
		new GameObject(1366 / 2, 768 - 100,  175, 40, 0, 2,0,false),
		new GameObject(75.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(155.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(235.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(315.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(395.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(475.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(555.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(635.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(715.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(795.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(875.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(955.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(1035.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(1115.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(1195.f, 100.f, 75, 40, 0, 0,2,false),
		new GameObject(75.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(155.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(235.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(315.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(395.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(475.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(555.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(635.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(715.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(795.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(875.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(955.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(1035.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(1115.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(1195.f, 145.f, 75, 40, 0, 0,2,false),
		new GameObject(75.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(155.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(235.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(315.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(395.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(475.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(555.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(635.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(715.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(795.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(875.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(955.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(1035.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(1115.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(1195.f, 190.f, 75, 40, 0, 0,2,false),
		new GameObject(75.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(155.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(235.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(315.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(395.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(475.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(555.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(635.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(715.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(795.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(875.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(955.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(1035.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(1115.f, 235.f, 75, 40, 0, 0,2,false),
		new GameObject(1195.f, 235.f, 75, 40, 0, 0,2,false),
	};

	return objectList;
}

int main()
{
    /*
    règles pour les pointeurs

    int i = 0;

    int* pi = &i;
    *pi = 7;

    int& ri = *pi;
    */

	bool isPlaying = true;
    float time = 0;
    bool fire = true;

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Casse Brique" /*, sf::Style::Fullscreen*/);
    sf::Clock timer;
	vector<GameObject*>objectList;

    float windowSizeX = window.getSize().x;
    float windowSizeY = window.getSize().y;

	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("font/Star_Cartoon.ttf"))
	{
		cout << "failed to load font" << std::endl;
	}

	objectList = initialisationList();

    while (window.isOpen())
    {
		while (isPlaying == true) {
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonPressed:
					if (objectList[0]->fired) {
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							objectList[0]->shoot(objectList, sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
							window.draw(*objectList[0]->circleDisplay());
							objectList[0]->fired = false;
						}
					}
					break;

				default:
					break;
				}
			}

			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			window.clear(sf::Color(53, 114, 127, 255));

			if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == true) {
				objectList[0]->movement(time, windowSizeX, windowSizeY);
			}
			if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == false) {
				objectList[0]->movement(time, windowSizeX, windowSizeY);
			}

			for (int i = 0; i < objectList.size(); i++) {
				if (objectList[i]->shapeType == 0) {
					window.draw(*objectList[i]->rectangleDisplay());
				}
				else if (objectList[i]->shapeType == 1) {
					window.draw(*objectList[i]->circleDisplay());
				}
				else if (objectList[i]->shapeType == 2) {
					window.draw(objectList[i]->canonDisplay(mousePosition, windowSizeX, windowSizeY));

					/*sf::Vertex line[] =
					{
						sf::Vertex(sf::Vector2f(mousePosition.x, mousePosition.y)),
						sf::Vertex(sf::Vector2f(objectList[i]->posX, objectList[i]->posY))
					};

					window.draw(line, 2, sf::Lines);*/
				}
			}

			// Remaining Bricks Counter
			int brickCount = 60;

			for (int i = 0; i < objectList.size(); i++) {
				if (objectList[i]->shapeType == 0) {
					if (objectList[i]->posX == -1 && objectList[i]->posY == -1) {
						brickCount = brickCount - 1;
					}
				}
			}

			// Remaining Bricks Counter Display
			text.setFont(font);
			text.setString("Remaining Bricks :");
			text.setCharacterSize(24);
			text.setPosition(10, 5);
			window.draw(text);

			sf::Text bCount;
			bCount.setFont(font);
			bCount.setString(to_string(brickCount));
			bCount.setCharacterSize(24);
			bCount.setPosition(240, 5);
			window.draw(bCount);

			if (brickCount == 0) {
				isPlaying = false;
				if (isPlaying == false) {
					sf::Text win;
					win.setFont(font);
					win.setString("You Won !");
					win.setCharacterSize(100);
					win.setPosition(windowSizeX / 2 - 250, windowSizeY / 2 - 100);
					window.draw(win);

					sf::Text restart;
					restart.setFont(font);
					restart.setString("Press space to restart");
					restart.setCharacterSize(20);
					restart.setPosition(windowSizeX / 2 + 50, windowSizeY / 2 + 20);
					window.draw(restart);
				}
			}

			window.display();
			time = timer.restart().asSeconds();
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) {
					isPlaying = true;
					objectList = initialisationList();
					window.clear();
					cout << isPlaying;
				}
				break;
			}
		}
	}
    return 0;
}