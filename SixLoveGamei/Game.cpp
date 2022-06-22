#include"Game.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void Game::setGameArray(int short A[][6])
{
	srand(time(0));

	for (int i = 0; i < 6; i++)
	{
	repeat:
		for (int j = 0; j < 6; j++)
		{
			A[i][j] = rand() % 6 + 1;

			for (int h = 0; h < j; h++)
			{
				while (A[i][j] == A[i][h])
				{
					A[i][j] = rand() % 6 + 1;
					goto repeat;
				}
			}
			for (int k = 0; k < i; k++)
			{
				while (A[i][j] == A[k][j])
				{
					A[i][j] = rand() % 6 + 1;
					goto repeat;
				}
			}
		}
	}
};

void Game::copyGameArray(int short A[][6], int short B[][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			B[i][j] = A[i][j];
	}
};

void Game::removeNumbers(int short A[][6], int short amount) {
	int count(0), randnum(0);
	while (count != amount) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				randnum = rand() % 6 + 1;
				if ((randnum == A[i][j]) && count < amount) {
					A[i][j] = 0;
					count++;
				}
			}
		}
	}
};

void Game::displayArray(int short A[][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j == 5)
				cout << A[i][j] << endl;
			else
				cout << A[i][j] << "|";
		}
		if (i != 5)
			cout << "-----------" << endl;
	}
};

bool Game::checkGameArray(int short A[][6])
{
	bool gameState; int entry(0);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			if (A[i][j] == 0)
				entry++;
	}

	if (entry == 0)
		gameState = true;
	else
		gameState = false;
	return gameState;
};

int Game::stringToGame(std::string level){
	if(level == "Rookie"){
		return 2;
	} else if (level == "TUFFTONG")
	{
		return 3;
	} else if (level == "HARDSEED")
	{
		return 4;
	} else if (level == "Quit")
	{
		return 5;
	}
	else
	{
		return 10;
	}
}