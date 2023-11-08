#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Collider {
public:
	bool AABBCollider();
	bool circleCollider();
};