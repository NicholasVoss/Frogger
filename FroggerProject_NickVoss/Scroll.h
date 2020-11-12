#ifndef CSCROLL_PLAYER_H
#define CSCROLL_PLAYER_H

#include "GameObject.h"

class Scroll : public GameObject
{
    public:
        Scroll();
        virtual ~Scroll();
        SDL_Rect destscr;
        SDL_Rect src;   // Where to get Image (Part of Big Image
        void display(SDL_Renderer *prenderer);
        int loadPlayer(SDL_Renderer *prenderer);
        void set_scroll_loc(int sx, int sy, int sw, int sh)
        {
            src.x = sx;
            src.y = sy;
            src.w = sw,
            src.h = sh;
        }
        void move();
    protected:
    private:
};

#endif // CSCROLL_PLAYER_H
