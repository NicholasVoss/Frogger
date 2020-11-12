#include "GameObject.h"
#pragma once
class Frog: public GameObject
{
public:
	Frog();
	Frog(string s, int x, int y, int xv, int yx) :
		GameObject(s, x, y, xv, yx)
	{

	};
	~Frog();

	int lives = 3;
	int highestDistance = 0;
	int currentDistance = 0;

	void move();
	void reset();
	void die();
};

