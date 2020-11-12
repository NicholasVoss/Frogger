//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "mywindow.h"
#include <iostream>
#include "GameObject.h"
#include "Frog.h"
#include "Scroll.h"
#include "Log.h"
#include "Car.h"

using namespace std;

#define TICK_INTERVAL    10
#define MAX_SPEED       1
#define JUMP_DISTANCE	45
#define LOGS_PER_ROW	4
#define CARS_PER_ROW	3
#define ROWS			5

//==============================================================================
class Game
{
private:
    bool Running;
	bool gameOver = false;

	int score = 0;

    Uint32 next_time;

    SDL_Window *window;
    SDL_Renderer *renderer;
    GameObject background;
    Frog froggy;
	Scroll water;
	Log logs[LOGS_PER_ROW][ROWS];
	Car cars[CARS_PER_ROW][ROWS];

	TTF_Font* font;
	SDL_Color color;
	char message[100];
	SDL_Surface* messageSurface;
	SDL_Texture* messageTexture;
	SDL_Rect messageRect;

	Mix_Music* music = NULL;
	Mix_Chunk* hopSound = NULL;
	Mix_Chunk* deathSound = NULL;

public:
    Game();
    Uint32 time_left(void);
    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Texture* &psprite, SDL_Rect *prect);
    void MoveSprites();

	bool check_collision(SDL_Rect A, SDL_Rect B);

	void displayGameStats(int x, int y, char* formattedString, int number);

	void OnCleanup();
};

//==============================================================================

#endif
