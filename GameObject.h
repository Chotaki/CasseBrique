#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class GameObject
{
public:
	int posX;
	int posY;
	int width;
	int height;
	int radius;
	int rectangleOrCircle;
	// shape canon
	// orientation pour canon
	// vitatilité pour brique
	// mouvement boule

	GameObject(int positionX, int positionY, int w, int h, int r, int rOC);

	sf::RectangleShape rectangleDisplay(int positionX, int positionY, int w, int h);
	sf::CircleShape circleDisplay(int positionX, int positionY, int r);
	sf::CircleShape canonDisplay(int positionX, int positionY, int r);
};