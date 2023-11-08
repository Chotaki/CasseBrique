#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameObject.h"

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
	pRect.setPosition(posX, posX);
	return &pRect;
}

sf::Shape* GameObject::circleDisplay() {
	sf::Shape* circle = shape;
	sf::Shape& pCirc = *circle;
	pCirc.setFillColor(sf::Color(200, 200, 200));
	pCirc.setPosition(posX, posY);
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

void GameObject::movement(float t, float x, float y) {
	if( 0 < posX && posX < x && 0 < posY && posY < y){
		posX += directionX * t * 10.f;
		posY += directionY * t * 10.f;
	}
}

bool GameObject::isColliding(vector<GameObject*> l) {
	// Collisions SFML
	/*sf::FloatRect boundingBox = shape->getGlobalBounds();
	for (int i = 0; i < l.size(); i++) {
		if (shapeType != l[i]->shapeType) {
			sf::FloatRect otherBox = l[i]->shape->getGlobalBounds();
			if (boundingBox.intersects(otherBox)) {
				return true;
			}
		}
	}
	return false;*/

	// Collisions Manuelles
	if (shapeType == 1) {
		height = radius * 2;
		width = radius * 2;
	}

	int Xmin = posX;
	int Xmax = posX + width;
	int Ymin = posY;
	int Ymax = posY + height;

	for (int i = 0; i < l.size(); i++) {

		if (l[i]->shapeType == 0) {
			cout << l[i]->shapeType << " truc" << endl;
			int otherXmin = l[i]->posX;
			int otherXmax = l[i]->posX + l[i]->width;
			int otherYmin = l[i]->posY;
			int otherYmax = l[i]->posY + l[i]->height;

			
			if (otherXmin <= Xmin && otherXmax >= Xmin || otherXmin <= Xmax && otherXmax >= Xmax) {
				cout << "aaaaaaaaa";
				return true;	
			}


			//l[i]->posX (l[i]->posX + l[i]->width) (posX) (posX+width)
		}
	}
	return false;
}