//==============================================================================
#include "Game.h"

//==============================================================================
void Game::OnRender()
{
    SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
    SDL_RenderClear(renderer);

    background.display(renderer);
	water.display(renderer);
	
	//render logs
	for (int i = 0; i < LOGS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			logs[i][j].display(renderer);
		}
	}

	//render cars
	for (int i = 0; i < CARS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			cars[i][j].display(renderer);
		}
	}

    froggy.display(renderer);

	displayGameStats(20, 20, "Score: %3d", score);
	displayGameStats(500, 20, "Lives Left: %2d", froggy.lives);

	//show game over screen if player runs out of lives
	if (froggy.lives <= 0)
	{
		gameOver = true;
		SDL_RenderClear(renderer);
		displayGameStats(window_w / 2 - 100, window_h / 2 - 50, "Game Over", 0);
		displayGameStats(window_w / 2 - 100, window_h / 2, "Score: %3d", score);
	}

    /* Update the screen! */
    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;

}

//==============================================================================
