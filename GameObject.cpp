#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(int positionX, int positionY, int w, int h, int r, int rOC,float dirX, float dirY) {
	posX = positionX;
	posY = positionY;
	width = w;
	height = h;
	radius = r;
	rectangleOrCircle = rOC;
	directionX = dirX;
	directionY = dirY;
}

sf::RectangleShape GameObject::rectangleDisplay() {
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color(0, 250, 250));
	rectangle.setPosition(posX, posX);
	return rectangle;
}

sf::CircleShape GameObject::circleDisplay() {
	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color(200, 200, 200));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color(150, 150, 150));
	circle.setPosition(posX, posY);
	return circle;
}

sf::CircleShape GameObject::triangleDisplay() {
	sf::CircleShape triangle(radius,3);
	triangle.setFillColor(sf::Color(0, 0, 250));
	triangle.setPosition(posX, posY);
	return triangle;
}

void GameObject::movement(float t) {
	posX += directionX * t * 10.f;
	posY += directionY * t * 10.f;
}