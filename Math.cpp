#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Math.h"

using namespace std;

// Normalising a vector 
sf::Vector2f Math::Normalized(sf::Vector2f oDirection){

	sf::Vector2f cache = oDirection;
	oDirection.x /= sqrt(cache.x * cache.x + cache.y * cache.y);
	oDirection.y /= sqrt(cache.x * cache.x + cache.y * cache.y);
	return oDirection;
};