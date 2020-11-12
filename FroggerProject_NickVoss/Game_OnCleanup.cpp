//==============================================================================
#include "Game.h"

//==============================================================================
void Game::OnCleanup() {

	//Close the font
	TTF_CloseFont(font);

	//Cleanup sounds/music
	Mix_FreeChunk(hopSound);
	Mix_FreeChunk(deathSound);
	Mix_FreeMusic(music);
	hopSound = NULL;
	deathSound = NULL;
	music = NULL;
	Mix_CloseAudio();


    //SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

//==============================================================================
