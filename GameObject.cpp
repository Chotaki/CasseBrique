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

	if (shapeType == 0) {
		shape = new sf::RectangleShape(sf::Vector2f(width, height));
	}
	else if (shapeType == 1) {
		shape = new sf::CircleShape(radius);
	}
	else if (shapeType == 2) {
		//shape = new sf::RectangleShape(sf::Vector2f(width, height));
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

sf::Shape* GameObject::rectangleDisplay() {
	sf::Shape* rectangle = shape;
	sf::Shape& pRect = *rectangle;
	if ( health == 2){
		pRect.setFillColor(sf::Color(99, 225, 124));
	}
	else if (health == 1) {
		pRect.setFillColor(sf::Color(236, 163, 79));
	}
	else if (health == 0) {
		pRect.setFillColor(sf::Color(255, 81, 81));
	}
	pRect.setPosition(posX, posY);
	return &pRect;
}

sf::Shape* GameObject::circleDisplay() {
	sf::Shape* circle = shape;
	sf::Shape& pCirc = *circle;
	pCirc.setFillColor(sf::Color(222, 250, 252));
	return &pCirc;
}

sf::Sprite GameObject::canonDisplay(sf::Vector2i deg, float x, float y) {
	float rotation = 180;
	
	//sf::Shape* canon = shape;
	//sf::Shape& pCanon = *canon;

	if (0 < deg.x && deg.x < x && 0 < deg.y && deg.y < y) {
		rotation = -atan2(deg.x - posX , deg.y - posY ) * 180 / M_PI;
	}

	look.setPosition(posX, posY);
	look.setRotation(rotation + 180);
	look.setOrigin(width*2.35, height*2.35);
	look.setScale(0.25, 0.25);

	//pCanon.setOrigin(width/2, height/2);
	//pCanon.setRotation(rotation + 180);
	//pCanon.setPosition(posX, posY);
	//pCanon.setTexture(texture); // texture est un sf::Texture

	return look;
}
 
bool IsInsideInterval(int v, int vMin, int vMax) 
{
	return v >= vMin && v <= vMax;
}

bool GameObject::isColliding(vector<GameObject*> l, float x, float y, float t) {
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

	// window border collision
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
					//cout << "aaa" << endl;
				}
				else 
				{
					//OnCollisionEnter
					objectCollision.push_back(l[i]);

					l[i]->loseHealth();

					//cout << "bbb" << endl;

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

					//cout << "ccc" << endl;
				}

			}
		}
	}

	return false;
}

void GameObject::shoot(vector<GameObject*> l, sf::Vector2i mousePos) {
	
	int j ;

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
	//cout << direction.x << endl;
	posX += direction.x * t * 1000.f;
	posY += direction.y * t * 1000.f;
	shape->setPosition(posX, posY);	
}

void GameObject::changeDirection(sf::Vector2f oDirection) {
	direction = Math::Normalized(oDirection);
}

void GameObject::loseHealth(){
	if (health == 0) {
		height = 0;
		width = 0;
		posX = -1;
		posY = -1;
	}
	else {
		health -= 1;
	}
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
}