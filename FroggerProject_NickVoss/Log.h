#pragma once
#include "GameObject.h"
class Log : public GameObject
{
public:
	Log();
	Log(string s, int x, int y, int vx, int vy) :
		GameObject(s, x, y, vx, vy)
	{
		
	};
	~Log();

	void move();
};

