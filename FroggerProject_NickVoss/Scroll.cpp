#include "Scroll.h"

Scroll::Scroll()
{
    //ctor
}

Scroll::~Scroll()
{
    //dtor
}

void Scroll::display(SDL_Renderer *prenderer)
{
    SDL_RenderCopy(prenderer, texture, &src, &destscr);

}


int Scroll::loadPlayer(SDL_Renderer *prenderer)
{
    int retval;

    retval = GameObject::loadPlayer(prenderer);
    destscr.x = 0;
    destscr.y = 0;
    destscr.h = window_h;
    destscr.w = window_w;
    velocity.x = 1;
    velocity.y = 0;
    return (retval);
}



void Scroll::move()
{
    src.x += velocity.x;
    src.y += velocity.y;
    if (src.y >= position.h)
    {
        velocity.y = -velocity.y;
        src.y += velocity.y;
    }
    if (src.y < 0 )
    {
        velocity.y = -velocity.y;
        src.y += velocity.y;
    }
    if (src.x >= position.w - window_w)   // Assumes that image is greater than window width..
    {
		src.x = 0;
        src.x += velocity.x;
    }
    if (src.x < 0)
    {
        velocity.x = -velocity.x;
        src.x += velocity.x;
    }

}
