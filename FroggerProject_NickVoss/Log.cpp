#include "Log.h"

Log::Log()
{

}

Log::~Log()
{

}

void Log::move()
{
	SDL_Rect *p;
	SDL_Rect *v;

	p = &position;
	v = &velocity;

	p->x += v->x;

	p->y += v->y;

	//if log goes off screen, loop to the other side
	if (p->x < -500)
	{
		p->x = window_w;
	}
}