#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Math.h"

using namespace std;

GameObject::GameObject(float positionX, float positionY, int w, int h, int r, int rOC, int life, bool fire) {
	posX = positionX;
	posY = positionY;
	width = w;
	height = h;
	radius = r;
	shapeType = rOC;
	health = life;
	fired = fire;

	// Creating our shapes and initialasing our sprites
	if (shapeType == 0) {
		shape = new sf::RectangleShape(sf::Vector2f(width, height));
	}
	else if (shapeType == 1) {
		shape = new sf::CircleShape(radius);
	}
	else if (shapeType == 2) {
		sf::Texture texture;
		texture.loadFromFile("img/cannon.png");
		if (!texture.loadFromFile("img/cannon.png"))
		{
			cout << "failed to load image" << std::endl;
		}else{
			texture.setSmooth(true);

			textu = texture;

			sf::Sprite sprite;
			sprite.setTexture(textu);

			look = sprite;
		}
	}
}

// Display a rectangle
sf::Sprite GameObject::rectangleDisplay() {
	//sf::Shape* rectangle = shape;
	//sf::Shape& pRect = *rectangle;

	sf::Texture red;
	red.loadFromFile("img/red.png");
	if (!red.loadFromFile("img/red.png"))
	{
		cout << "failed to load image" << std::endl;
	}
	else {
		redText = red;

		sf::Sprite redSprite;
		redSprite.setTexture(redText);

		redLook = redSprite;
	}

	sf::Texture orange;
	orange.loadFromFile("img/orange.png");
	if (!orange.loadFromFile("img/orange.png"))
	{
		cout << "failed to load image" << std::endl;
	}
	else {
		orangeText = orange;

		sf::Sprite orangeSprite;
		orangeSprite.setTexture(orangeText);

		orangeLook = orangeSprite;
	}

	sf::Texture green;
	green.loadFromFile("img/green.png");
	if (!green.loadFromFile("img/green.png"))
	{
		cout << "failed to load image" << std::endl;
	}
	else {
		greenText = green;

		sf::Sprite greenSprite;
		greenSprite.setTexture(greenText);

		greenLook = greenSprite;
	}

	if ( health == 2){
		greenLook.setPosition(posX, posY);
		return greenLook;
		//pRect.setFillColor(sf::Color(99, 225, 124));
	}
	else if (health == 1) {
		orangeLook.setPosition(posX, posY);
		return orangeLook;
		//pRect.setFillColor(sf::Color(236, 163, 79));
	}
	else if (health == 0) {
		redLook.setPosition(posX, posY);
		return redLook;
		//pRect.setFillColor(sf::Color(255, 81, 81));
	}
}

// Display a circle
sf::Shape* GameObject::circleDisplay() {
	sf::Shape* circle = shape;
	sf::Shape& pCirc = *circle;
	pCirc.setFillColor(sf::Color(169, 208, 218));
	return &pCirc;
}

// Display a cannon
sf::Sprite GameObject::canonDisplay(sf::Vector2i deg, float x, float y) {
	float rotation = 180;

	if (0 < deg.x && deg.x < x && 0 < deg.y && deg.y < y) {
		rotation = -atan2(deg.x - posX , deg.y - posY ) * 180 / M_PI;
	}

	look.setPosition(posX, posY);
	look.setRotation(rotation + 180);
	look.setOrigin(width*2.35, height*2.35);
	look.setScale(0.25, 0.25);
	return look;
}
 
// Verification needed to check collisions
bool IsInsideInterval(int v, int vMin, int vMax) 
{
	return v >= vMin && v <= vMax;
}

// Collision check
bool GameObject::isColliding(vector<GameObject*> l, float x, float y, float t) {
	// Checking the collision on a circle only
	if (shapeType == 1) {
		height = radius * 2;
		width = radius * 2;
	}

	int Xmin = posX ;
	int Xmax = posX + width ;
	int Ymin = posY;
	int Ymax = posY + height;

	bool IsXminInsideScreen = IsInsideInterval(Xmin, 0, x);
	bool IsYminInsideScreen = IsInsideInterval(Ymin, 0, y);
	bool IsXmaxInsideScreen = IsInsideInterval(Xmax, 0, x);
	bool IsYmaxInsideScreen = IsInsideInterval(Ymax, 0, y);

	// Collisions with the window borders
	if (IsXminInsideScreen == false) {
		direction.x = -direction.x;
		return true;
	}
	else if (IsYminInsideScreen == false) {
		direction.y = -direction.y;
		return true;
	}
	else if (IsXmaxInsideScreen == false) {
		direction.x = -direction.x;
		return true;
	}
	else if (IsYmaxInsideScreen == false) {
		fired = true;
		objectCollision.clear();
		return true;
	}

	// Collisions with the bricks
	for (int i = 0; i < l.size(); i++) {

		if (l[i]->shapeType == 0) {

			int otherXmin = l[i]->posX;
			int otherXmax = l[i]->posX + l[i]->width;
			int otherYmin = l[i]->posY;
			int otherYmax = l[i]->posY + l[i]->height;

			bool IsYMinInside = IsInsideInterval(Ymin, otherYmin, otherYmax);
			bool IsYMaxInside = IsInsideInterval(Ymax, otherYmin, otherYmax);
			bool IsXMinInside = IsInsideInterval(Xmin, otherXmin, otherXmax);
			bool IsXMaxInside = IsInsideInterval(Xmax, otherXmin, otherXmax);

			auto it = std::find(objectCollision.begin(), objectCollision.end(), l[i]);

			if ((IsYMinInside || IsYMaxInside) && (IsXMinInside || IsXMaxInside))
			{
				if (it != objectCollision.end()) 
				{
					//OnCollisionStay
					direction.x = -direction.x;
					direction.y = -direction.y;
				}
				else 
				{
					//OnCollisionEnter
					objectCollision.push_back(l[i]);

					l[i]->loseHealth();

					if (IsYMinInside == true) {
						direction.y = -direction.y;
						return true;
					}
					else if (IsXMinInside == true) {
						direction.x = -direction.x;
						return true;
					}
					else if (IsXMaxInside == true) {
						direction.x = -direction.x;
						return true;
					}
					else if (IsYMaxInside == true) {
						direction.y = -direction.y;
						return true;
					}
				}
			}
			else 
			{
				if (it != objectCollision.end())
				{
					//OnCollisionExit
					objectCollision.erase(it);
				}

			}
		}
	}

	return false;
}

// Shooting ability
void GameObject::shoot(vector<GameObject*> l, sf::Vector2i mousePos) {
	
	int j ;

	// Possibility to shoot only from a cannon
	for (int i = 0; i < l.size(); i++ ){
		if(l[i]->shapeType == 2){
			j = i;
		}
	}

	posX = l[j]->posX - 10;
	posY = l[j]->posY - 10;
	
	sf::Vector2i mouseP = mousePos;
	sf::Vector2f mousePosF = sf::Vector2f(mouseP.x, mouseP.y);
	sf::Vector2f ballStartPos(l[j]->posX, l[j]->posY);
	sf::Vector2f direction = sf::Vector2f(mousePosF.x - ballStartPos.x, mousePosF.y - ballStartPos.y);
	changeDirection(direction);
}
 
void GameObject::movement(float t, float x, float y) {
	posX += direction.x * t * 1000.f;
	posY += direction.y * t * 1000.f;
	shape->setPosition(posX, posY);	
}

// Bounce
void GameObject::changeDirection(sf::Vector2f oDirection) {
	direction = Math::Normalized(oDirection);
}

// Bricks can lose health
void GameObject::loseHealth(){
	if (health == 0) {
		height = 0;
		width = 0;
		posX = -100;
		posY = -100;
		//redText = NULL;
	}
	else {
		health -= 1;
	}
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
}