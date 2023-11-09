#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Math.h"

using namespace std;

GameObject::GameObject(float positionX, float positionY, int w, int h, int r, int rOC,float dirX, float dirY) {
	posX = positionX;
	posY = positionY;
	width = w;
	height = h;
	radius = r;
	shapeType = rOC;
	directionX = dirX;
	directionY = dirY;

	if (shapeType == 0) {
		shape = new sf::RectangleShape(sf::Vector2f(width, height));
	}
	else if (shapeType == 1) {
		shape = new sf::CircleShape(radius);
	}
	else if (shapeType == 2) {
		shape = new sf::CircleShape(radius, 3);
	}
}

sf::Shape* GameObject::rectangleDisplay() {
	sf::Shape* rectangle = shape;
	sf::Shape& pRect = *rectangle;
	pRect.setFillColor(sf::Color(0, 250, 250));
	pRect.setPosition(posX, posY);
	return &pRect;
}

sf::Shape* GameObject::circleDisplay() {
	sf::Shape* circle = shape;
	sf::Shape& pCirc = *circle;
	pCirc.setFillColor(sf::Color(200, 200, 200));
	//pCirc.setPosition(posX, posY);
	return &pCirc;
}

sf::Shape* GameObject::triangleDisplay(sf::Vector2i deg, float x, float y) {
	float rotation = 180;

	sf::Shape* triangle = shape;
	sf::Shape& pTria = *triangle;

	if (0 < deg.x && deg.x < x && 0 < deg.y && deg.y < y) {
		rotation = -atan2(deg.x - (posX + radius / 2), deg.y - (posY + radius)) * 180 / M_PI;
	}

	pTria.setOrigin(radius, radius);
	pTria.setFillColor(sf::Color(0, 0, 250));
	pTria.setRotation(rotation - 180);
	pTria.setPosition(posX, posY);
	return &pTria;
}
 
bool IsInsideInterval(int v, int vMin, int vMax) 
{
	return v >= vMin && v <= vMax;
}

bool GameObject::isColliding(vector<GameObject*> l,float x, float y) {
	if (shapeType == 1) {
		height = radius * 2;
		width = radius * 2;
	}

	int Xmin = posX ;
	int Xmax = posX + width ;
	int Ymin = posY;
	int Ymax = posY + height;

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
			bool IsXminInsideScreen = IsInsideInterval(Xmin, 0, x);
			bool IsYminInsideScreen = IsInsideInterval(Ymin, 0, y);
			bool IsXmaxInsideScreen = IsInsideInterval(Xmax, 0, x);
			bool IsYmaxInsideScreen = IsInsideInterval(Ymax, 0, y);

			if (IsXminInsideScreen == false) {
				return true;
			}
			if (IsYminInsideScreen == false) {
				return true;
			}
			if (IsXmaxInsideScreen == false) {
				return true;
			}
			if (IsYmaxInsideScreen == false) {
				return true;
			}
			if ((IsYMinInside || IsYMaxInside) && (IsXMinInside || IsXMaxInside)) {
				return true;
			}
		}
	}
	return false;
}

void GameObject::shoot(vector<GameObject*> l, sf::Vector2i mousePos) {
	posX = l[2]->posX - 10;
	posY = l[2]->posY - 10;

	sf::Vector2i mouseP = mousePos;
	sf::Vector2f mousePosF = sf::Vector2f(mouseP.x, mouseP.y);
	sf::Vector2f ballStartPos(l[2]->posX, l[2]->posY);
	sf::Vector2f direction = sf::Vector2f(mousePosF.x - ballStartPos.x, mousePosF.y - ballStartPos.y);
	changeDirection(direction);
}

void GameObject::movement(float t, float x, float y) {
	posX += direction.x * t * 200.f;
	posY += direction.y * t * 200.f;
	shape->setPosition(posX, posY);	
}

void GameObject::changeDirection(sf::Vector2f oDirection) {
	direction = Math::Normalized(oDirection);
}