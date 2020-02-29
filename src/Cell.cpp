#include "Cell.h"

Cell::Cell()
{
	this->symbolAlive = 219;
	this->symbolDead = 176;
	this->alive = false;
}

void Cell::Cout()
{
	if (alive)
	{
		std::cout << symbolAlive;
	}
	else
	{
		std::cout << symbolDead;
	}
}

void Cell::SwitchState()
{
	alive = !alive;
}

void Cell::SetState(bool newState)
{
	alive = newState;
}

bool Cell::GetState()
{
	return alive;
}