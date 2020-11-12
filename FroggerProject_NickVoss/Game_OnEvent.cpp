//==============================================================================
#include "Game.h"

//==============================================================================
void Game::OnEvent(SDL_Event* Event) {
	switch (Event->type)
	{
	case SDL_QUIT:
		Running = false;
		break;

	case SDL_KEYDOWN:
		if (!gameOver)
		{
			switch (Event->key.keysym.sym)
			{
			case SDLK_RIGHT:
				if (froggy.position.x < window_w - froggy.position.w - JUMP_DISTANCE)
				{
					froggy.position.x += JUMP_DISTANCE;
					Mix_PlayChannel(-1, hopSound, 0);
				}
				break;
			case SDLK_LEFT:
				if (froggy.position.x >= JUMP_DISTANCE)
				{
					froggy.position.x -= JUMP_DISTANCE;
					Mix_PlayChannel(-1, hopSound, 0);
				}
				break;
			case SDLK_UP:
				if (froggy.position.y >= JUMP_DISTANCE)
				{
					froggy.position.y -= JUMP_DISTANCE;
					froggy.currentDistance++;
					Mix_PlayChannel(-1, hopSound, 0);

					if (froggy.currentDistance > froggy.highestDistance)
					{
						froggy.highestDistance++;
						score += 10;
					}
				}
				break;
			case SDLK_DOWN:
				if (froggy.position.y < window_h - JUMP_DISTANCE)
				{
					froggy.position.y += JUMP_DISTANCE;
					froggy.currentDistance--;
					Mix_PlayChannel(-1, hopSound, 0);
				}
				break;
			}
		}
    }
}

//==============================================================================
