#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class GameObject
{
public:
	float posX;
	float posY;
	int width;
	int height;
	int radius;
	int shapeType;
	sf::Vector2f direction;
	sf::Shape* shape;
	// shape canon
	// orientation pour canon
	// vitatilité pour brique
	// mouvement boule

	GameObject(float positionX, float positionY, int w, int h, int r, int rOC);

	sf::Shape* rectangleDisplay();
	sf::Shape* circleDisplay();
	sf::Shape* triangleDisplay(sf::Vector2i deg, float x, float y);
	void movement(float t, float x, float y);
	void movementInversX(float t, float x, float y);
	void movementInversY(float t, float x, float y);
	bool isColliding(vector<GameObject*> l, float x, float y, float t);
	void shoot(vector<GameObject*> l, sf::Vector2i mousePos);
	void changeDirection(sf::Vector2f oDirection);
};