#include "Frog.h"
Frog::Frog()
{

}

Frog::~Frog()
{

}

void Frog::move()
{
    SDL_Rect* p;
    SDL_Rect* v;

    p = &position;
    v = &velocity;

    p->x += v->x;

    p->y += v->y;

}

void Frog::reset()
{
	position.x = (window_w / 2) - (position.w / 2);
	position.y = window_h - position.h - 8;
	currentDistance = 0;
	highestDistance = 0;
	velocity.x = 0;
}
void Frog::die()
{
	reset();
	lives--;
}