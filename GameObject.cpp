#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(int positionX, int positionY, int w, int h, int r, int rOC) {
	posX = positionX;
	posY = positionY;
	width = w;
	height = h;
	radius = r;
	rectangleOrCircle = rOC;
}

sf::RectangleShape GameObject::rectangleDisplay(int positionX, int positionY, int w, int h) {
	sf::RectangleShape rectangle(sf::Vector2f(w, h));
	rectangle.setFillColor(sf::Color(0, 250, 250));
	rectangle.setPosition(positionX, positionX);
	return rectangle;
}

sf::CircleShape GameObject::circleDisplay(int positionX, int positionY, int r) {
	sf::CircleShape circle(r);
	circle.setFillColor(sf::Color(200, 200, 200));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color(150, 150, 150));
	circle.setPosition(positionX, positionY);
	return circle;
}

sf::CircleShape GameObject::canonDisplay(int positionX, int positionY, int r) {
	sf::CircleShape canon(r,3);
	canon.setFillColor(sf::Color(0, 0, 250));
	canon.setPosition(positionX, positionY);
	return canon;
}