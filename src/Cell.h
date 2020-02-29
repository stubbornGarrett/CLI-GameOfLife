#pragma once
#include <iostream>

class Cell
{
public:
	Cell();
	void Cout();
	void SwitchState();
	void SetState(bool newState);
	bool GetState();

private:
	char symbolAlive;
	char symbolDead;
	bool alive;
};

