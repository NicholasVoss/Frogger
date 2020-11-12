#include "Car.h"

Car::Car()
{

}

Car::~Car()
{

}

void Car::move()
{
	SDL_Rect *p;
	SDL_Rect *v;

	p = &position;
	v = &velocity;

	p->x += v->x;

	p->y += v->y;

	//if car goes off screen, loop to the other side
	if (p->x < -200)
	{
		p->x = window_w;
	}
	if (p->x > window_w + 200)
	{
		p->x = -200;
	}
}