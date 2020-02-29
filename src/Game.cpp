#include "Game.h"

Game::Game()
{
	Init();
}

void Game::Init()
{
	// Position of pattern
	int x = 5;
	int y = 24;

	for (int i = 0; i < 40; i++)
	{
		if (!(i > 8 && i < 10) && !(i > 14 && i < 18) && !(i > 20 && i < 27) && !(i > 34 && i < 36))
		{
			fieldOriginal[x + i][y].SwitchState();
		}
	}
}

void Game::Update()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int aliveNeighbors = 0;
			for (int yPos = -1; yPos < 2; yPos++)
			{
				for (int xPos = -1; xPos < 2; xPos++)
				{
					if ((y + yPos > 0 && y + yPos < height) && (x + xPos > 0 && x + xPos < width) && !(yPos == 0 && xPos == 0))
					{
						if (fieldOriginal[x + xPos][y + yPos].GetState())
						{
							aliveNeighbors++;
						}
					}
				}
			}

			if (!fieldOriginal[x][y].GetState() && aliveNeighbors == 3)
			{
				fieldBuffer[x][y].SetState(true);
			}
			else if (fieldOriginal[x][y].GetState() && (aliveNeighbors < 2 || aliveNeighbors > 3))
			{
				fieldBuffer[x][y].SetState(false);
			}
			else if (fieldOriginal[x][y].GetState())
			{
				fieldBuffer[x][y].SetState(true);
			}
		}
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			fieldOriginal[x][y].SetState(fieldBuffer[x][y].GetState());
		}
	}
}

void Game::Display()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			fieldOriginal[x][y].Cout();
		}
		std::cout << std::endl;
	}
}

bool Game::AllDead()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (fieldOriginal[x][y].GetState())
			{
				return false;
			}
		}
	}
	return true;
}