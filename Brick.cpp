/*#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Brick.h"

using namespace std;

Brick::Brick(int life, float positionX, float positionY, int w, int h, int r, int rOC) : GameObject(positionX,  positionY,  w,  h, r,  rOC)
{
	health = life;
}

void Brick::loseHealth() {
	if (health == 0){
		posX = -1;
		posY = -1;
		height = 0;
		width = 0;
	} else {
		health -= 1;
	}
};*/