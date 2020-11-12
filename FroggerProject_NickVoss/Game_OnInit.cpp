//==============================================================================
#include "Game.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool Game::OnInit()
{

    int i;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0)
    {
        return false;
    }

	//initialize text
	TTF_Init();
	font = TTF_OpenFont("gameplay.ttf", 25);
	color = { 255, 255, 255 };

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		//success = false;
	}


	music = Mix_LoadMUS("Music.wav");
	deathSound = Mix_LoadWAV("sound-frogger-squash.wav");
	hopSound = Mix_LoadWAV("Jump.wav");

	Mix_PlayMusic(music,-1);
	


	//initialize window
    window = SDL_CreateWindow("Basic SDL 2.0 Scrolling",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;

    srand(time(NULL));

    background = GameObject("froggerBackground.bmp", 0, 0, 0, 0);
    background.loadPlayer(renderer);
    
    froggy = Frog("froggy.bmp", 0, 0, 0, 0);
    froggy.loadPlayer(renderer);
	froggy.position.x = (window_w /2) - (froggy.position.w /2);
	froggy.position.y = window_h - froggy.position.h - 8;
	froggy.hitbox.w = (froggy.position.w * .5) + (froggy.position.w * .25);
	froggy.hitbox.h = (froggy.position.h * .5) + (froggy.position.h * .25);

	water.imagename = "water.bmp";
	water.loadPlayer(renderer);
	water.set_scroll_loc(0, 200, 960, 220);
	water.destscr.x = 0;
	water.destscr.y = 134;
	water.destscr.w = 960;
	water.destscr.h = 220;
	water.velocity.x = 1;

	water.hitbox.x = 0;
	water.hitbox.y = 134;
	water.hitbox.w = window_w;
	water.hitbox.h = 220;


	//position logs
	for (int i = 0; i < LOGS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (j == 0) 
			{
				logs[i][j] = Log("sprite-log-small.bmp", window_w + (600 * i), 135 + (45 * j), -2, 0);
				logs[i][j].loadPlayer(renderer);
			}
			if (j == 1)
			{
				logs[i][j] = Log("sprite-log-small.bmp", window_w + (400 * i), 135 + (45 * j), -1, 0);
				logs[i][j].loadPlayer(renderer);
			}
			if (j == 2)
			{
				logs[i][j] = Log("sprite-log-medium.bmp", window_w + (400 * i), 135 + (45 * j), -2, 0);
				logs[i][j].loadPlayer(renderer);
			}
			if (j == 3)
			{
				logs[i][j] = Log("sprite-log-small.bmp", window_w + (300 * i), 135 + (45 * j), -1, 0);
				logs[i][j].loadPlayer(renderer);
			}
			if (j == 4)
			{
				logs[i][j] = Log("sprite-log-large.bmp", window_w + (600 * i), 135 + (45 * j), -3, 0);
				logs[i][j].loadPlayer(renderer);
			}
		}
	}

	//position cars
	for (int i = 0; i < CARS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (j == 0)
			{
				cars[i][j] = Car("sprite-vehicle-bluecar.bmp", -(400 * i), 405 + (45 * j), 2, 0);
				cars[i][j].loadPlayer(renderer);
			}
			if (j == 1)
			{
				cars[i][j] = Car("sprite-vehicle-greencar.bmp", window_w + (200 * i), 405 + (45 * j), -3, 0);
				cars[i][j].loadPlayer(renderer);
			}
			if (j == 2)
			{
				cars[i][j] = Car("sprite-vehicle-bluecar.bmp", -(200 * i), 405 + (45 * j), 1, 0);
				cars[i][j].loadPlayer(renderer);
			}
			if (j == 3)
			{
				cars[i][j] = Car("sprite-vehicle-greencar.bmp", (300 * i), 405 + (45 * j), -1, 0);
				cars[i][j].loadPlayer(renderer);
			}
			if (j == 4)
			{
				cars[i][j] = Car("sprite-vehicle-bluecar.bmp", -(300 * i), 405 + (45 * j), 1, 0);
				cars[i][j].loadPlayer(renderer);
			}
		}
	}



    return true;
}




//==============================================================================
