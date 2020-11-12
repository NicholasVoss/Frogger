//==============================================================================
#include "Game.h"

void
Game::MoveSprites()
{
	bool frogOnLog = false;
	int logSpeed = 0;

	//move frog hitbox
	froggy.hitbox.x = froggy.position.x + froggy.position.w/4;
	froggy.hitbox.y = froggy.position.y + froggy.position.h/4;

	//move logs
	for (int i = 0; i < LOGS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			logs[i][j].move();
		}
	}

	//check if frog landed on log
	for (int i = 0; i < LOGS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (check_collision(froggy.hitbox, logs[i][j].position))
			{
				logSpeed = logs[i][j].velocity.x;
				frogOnLog = true;
			}
		}
	}
	//move frog with log
	if (frogOnLog)
	{
		froggy.velocity.x = logSpeed;
	}
	//check if frog falls into water
	else if (!frogOnLog && check_collision(froggy.hitbox, water.hitbox))
	{
		froggy.die();
		Mix_PlayChannel(-1, deathSound, 0);
	}
	else //stop moving when frog is not on log
	{
		froggy.velocity.x = 0;
	}


	//check if frog reaches top of screen
	if (froggy.position.y < 100)
	{
		score += 100;
		froggy.reset();
	}

	//move cars
	for (int i = 0; i < CARS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			cars[i][j].move();
		}
	}

	//check if car hits frog
	for (int i = 0; i < CARS_PER_ROW; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (check_collision(froggy.hitbox, cars[i][j].position))
			{
				froggy.die();
				Mix_PlayChannel(-1, deathSound, 0);
			}
		}
	}

	//kill frog if it goes off screen
	if (froggy.position.x > window_w || froggy.position.x < -froggy.position.w)
	{
		froggy.die();
		Mix_PlayChannel(-1, deathSound, 0);
	}

	froggy.move();
	water.move();
}


//==============================================================================
void Game::OnLoop()
{
    MoveSprites();

}

//==============================================================================
