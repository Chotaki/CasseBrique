#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>

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
	vector<GameObject*>objectCollision;
	sf::Texture textu;
	sf::Sprite look;
	sf::Texture redText;
	sf::Sprite redLook;
	sf::Texture orangeText;
	sf::Sprite orangeLook;
	sf::Texture greenText;
	sf::Sprite greenLook;
	
	int health;
	bool fired;

	GameObject(float positionX, float positionY, int w, int h, int r, int rOC, int life, bool fire);

	sf::Sprite rectangleDisplay();
	sf::Shape* circleDisplay();
	sf::Sprite canonDisplay(sf::Vector2i deg, float x, float y);
	void movement(float t, float x, float y);
	bool isColliding(vector<GameObject*> l, float x, float y, float t);
	void shoot(vector<GameObject*> l, sf::Vector2i mousePos);
	void changeDirection(sf::Vector2f oDirection);
	void loseHealth();
};