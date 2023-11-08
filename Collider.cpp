#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Collider.h"

/*

collider rectangle = 
	posX posY to PosX height to width posY to width height 

collider circle = 
	posX posY | 2 * pi * radius 


*/

bool Collider::AABBCollider() {
	float side1;
	float side2;
	float side3;
	float side4;

	return false;
}

bool Collider::circleCollider() {
	return false;
}