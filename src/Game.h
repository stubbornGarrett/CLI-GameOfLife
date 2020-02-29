#pragma once
#include "Cell.h"

class Game
{
public:
	Game();
	void Init();
	void Update();
	void Display();
	bool AllDead();

private:
	static const int width = 50;
	static const int height = 50;
	Cell fieldOriginal[width][height];
	Cell fieldBuffer[width][height];
};

