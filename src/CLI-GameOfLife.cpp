/*
Conway's Game of Life
2019-02-29

Fixed field size (50x50 at this point)
Patterns is hardcoded. No user input while runtime.

Current pattern:
-----------------------------------------
-########-#####---###------#######-#####-
-----------------------------------------

Only executable on Windows cmd
*/

#include "Game.h"
#include <windows.h>
#include <time.h>

void ClearScreen()
{
    system("cls");
}

int main()
{
	bool running = true;
	Game GameOfLife;

	do
	{
		GameOfLife.Display();
        Sleep(20);
        GameOfLife.Update();
        ClearScreen();
    } while (!GameOfLife.AllDead());
    
    // Won't reach this point in current scenario

    return 0;
}
