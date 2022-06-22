#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl;

void Game::setGameArray(std::array <std::array< int,colums>, rows>& solutionArray)
{
	srand(time(0));

	for (size_t i = 0; i < solutionArray.size(); i++)
	{
	repeat:
		for (size_t j = 0; j < solutionArray.size(); j++)
		{
			solutionArray[i][j] = rand() % colums + 1;

			for (size_t h = 0; h < j; h++)
			{
				while (solutionArray[i][j] == solutionArray[i][h])
				{
					solutionArray[i][j] = rand() % colums + 1;
					goto repeat;
				}
			}
			for (int k = 0; k < i; k++)
			{
				while (solutionArray[i][j] == solutionArray[k][j])
				{
					solutionArray[i][j] = rand() % colums + 1;
					goto repeat;
				}
			}
		}
	}
};

void Game::copyGameArray(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray)
{
	for (auto const row : solutionArray)
	{
		for (auto const element : row)
			playerArray = solutionArray;
	}
};

void Game::removeNumbers(std::array <std::array< int,colums>, rows>& Array, int amount) {
	int count(0), randnum(0);
	while (count != amount) {
		for (auto& row : Array) {
			for (auto& element : row) {
				randnum = rand() % colums + 1;
				if ((randnum == element) && count < amount) {
					element = 0;
					count++;
				}
			}
		}
	}
};

void Game::displayArray(std::array <std::array< int,colums>, rows>& Array)
{
	cout << endl << "-------------------------" << endl;
	for (auto const& row : Array)
	{
		cout<<"| ";
		for (auto const& element : row)
		{
			cout << element << " | ";
		}
			cout << endl << "-------------------------" << endl;
	}
};

bool Game::checkGameArray(std::array <std::array< int,colums>, rows>& playerArray)
{
	int unfilled(0);

	for (auto const row : playerArray)
	{
		for (auto const element : row)
			if (element == 0)
				unfilled++;
	}
	return (unfilled != 0)? false : true;
};

int Game::stringToGame(std::string level){
	std::transform(level.begin(), level.end(), level.begin(), ::toupper);
	if(level == "ROOKIE" || level == "R"){
		return 20;
	} else if (level == "TUFFTONG" || level == "T" )
	{
		return 21;
	} else if (level == "HARDSEED" || level == "H")
	{
		return 22;
	} else if (level == "QUIT" || level == "Q")
	{
		return 50;
	}
	else
	{
		return 30;
	}
}

void Game::intro(std::string name){
	cout << "Welcome "<<name<<" to the game of SIX LOVE!!"<<endl<<
	"This game features a 6x6 grid where, the elements in the grid range from 1 to 6."<<endl<<
	"Each row and column has only one instant of each digit."<<endl<<endl<<
	"This game has three levels:\n   (1) Rookie \n   (2) Tuff Tong \n   (3) Hard Seed"<<endl<<endl<<
	"Rules:"<<endl<<endl<<"To choose a level you must enter the first letter that corresponds to intended level (i.e. 'r' or 'R' for Rookie)."<<endl<<
	"To play successfully you are required to enter a row number from 1 to 6 (inlcusive)," <<endl<<
    "similarly with column number and your input, to fill the slots that have zeros."<<endl<<endl<<
	"At any prompt during the game you can quit by entering the number '99'."<<endl<<
	"HOWEVER, DO NOT ENTER A NUMBER WHEN PROMPT FOR A HINT, INSTEAD ENTER THE LETTER 'Q'"<<endl<<endl<<
	"Rookie has a maximum of 1 hint, Tuff Tong has a maximum of 2 hints and Hard Seed has a maximum of 3 hints."<<endl<<
	"Request any higher than the amount allotted for each level, the game will end and you will be awarded zero points."<<endl<<endl<<"Enjoy the game!!"<<endl<<endl;
}

bool Game::checkEntry(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray, size_t rn,size_t cn ,size_t pn){
	if (pn == solutionArray[rn][cn]){
		playerArray[rn][cn] = pn;
		return true;
	}
	else
		return false;
}
bool Game::checkIfFilled(std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn){
	return (playerArray[rn][cn] != 0)? true :false;
}

int Game::stringToGameEnd(std::string endGame){
	std::transform(endGame.begin(), endGame.end(), endGame.begin(), ::toupper);
	if(endGame== "YES" || endGame == "YE" || endGame == "Y"){
		return 90;
	} else if (endGame == "NO" || endGame == "N" )
	{
		return 91;
	}
	else
	{
		return 95;
	}
}