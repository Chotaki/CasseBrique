#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameObject.h"

using namespace std;

// Initialise the bricks, the ball and the cannon
vector<GameObject*> initialisationList() {
	vector<GameObject*>objectList;

	objectList = {
		// 0 = rectangle (w,h) | 1 = circle (r) | 2 = cannon
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

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Casse Brique");
    sf::Clock timer;
	vector<GameObject*>objectList;

    float windowSizeX = window.getSize().x;
    float windowSizeY = window.getSize().y;

	// Loading main music
	sf::Music  music;
	if (!music.openFromFile("sound/sound.wav")){

		cout << "failed to load music" << endl;

	}else {
		cout << " music loaded" << endl;
	}

	// Loading Cannon sound
	sf::SoundBuffer buffer;
	sf::Sound sound;
	if (!buffer.loadFromFile("sound/cannon.wav")){

		cout << "failed to load sound" << std::endl;

	}else {
		sound.setBuffer(buffer);
		
	}
		
	
	// Loading the text and font
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("font/Star_Cartoon.ttf"))
	{
		cout << "failed to load font" << std::endl;
	}

	// Load Background Image
	sf::Texture background;
	sf::Sprite bgSprite;
	background.loadFromFile("img/background.jpg");
	if (!background.loadFromFile("img/background.jpg"))
	{
		cout << "failed to load background" << std::endl;
	}
	else {
		background.setSmooth(true);

		bgSprite.setTexture(background);
		bgSprite.scale(0.353, 0.353);
	}

	objectList = initialisationList();

    while (window.isOpen())
    {
		// Play main music
		music.setLoop(true);
		music.setVolume(2);
		music.play();

		while (isPlaying == true) {

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type) {

				// Ability to close the window
				case sf::Event::Closed:
					music.stop();
					window.close();
					break;

				// Ability to shoot
				case sf::Event::MouseButtonPressed:
					if (objectList[0]->fired) {
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							sound.setVolume(50);
							sound.play();
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

			// Getting the mouse position
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			// Creating a base background while clearing the window
			window.clear(sf::Color::White);

			// Display background image
			window.draw(bgSprite);

			// Collision check
			if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == true) {
				objectList[0]->movement(time, windowSizeX, windowSizeY);
			}
			if (objectList[0]->isColliding(objectList, windowSizeX, windowSizeY, time) == false) {
				objectList[0]->movement(time, windowSizeX, windowSizeY);
			}

			// Drawing each shape on the screen
			for (int i = 0; i < objectList.size(); i++) {
				if (objectList[i]->shapeType == 0) {
					window.draw(objectList[i]->rectangleDisplay());
				}
				else if (objectList[i]->shapeType == 1) {
					window.draw(*objectList[i]->circleDisplay());
				}
				else if (objectList[i]->shapeType == 2) {
					window.draw(objectList[i]->canonDisplay(mousePosition, windowSizeX, windowSizeY));

					//Possibility to draw a line following the mouse position
					/* sf::Vertex line[] =
					{
						sf::Vertex(sf::Vector2f(mousePosition.x, mousePosition.y)),
						sf::Vertex(sf::Vector2f(objectList[i]->posX, objectList[i]->posY))
					};

					window.draw(line, 2, sf::Lines); */
				}
			}

			// Remaining Bricks Counter
			int brickCount = 60;

			for (int i = 0; i < objectList.size(); i++) {
				if (objectList[i]->shapeType == 0) {
					if (objectList[i]->posX == -100 && objectList[i]->posY == -100) {
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

			// Win condition
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

		// Events possible on the win screen
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			// Closing the window
			case sf::Event::Closed:
				window.close();
				break;

			// Pressing space to restart the game
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