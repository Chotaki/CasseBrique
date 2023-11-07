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
	float directionX;
	float directionY;
	// shape canon
	// orientation pour canon
	// vitatilité pour brique
	// mouvement boule

	GameObject(int positionX, int positionY, int w, int h, int r, int rOC, float dirX, float dirY);

	sf::RectangleShape rectangleDisplay();
	sf::CircleShape circleDisplay();
	sf::CircleShape triangleDisplay();
	void movement(float t);
};