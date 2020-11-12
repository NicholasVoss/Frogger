#pragma once
#include "GameObject.h"
class Car : public GameObject
{
public:
	Car();
	Car(string s, int x, int y, int vx, int vy) :
		GameObject(s, x, y, vx, vy)
	{

	};
	~Car();

	void move();
};

