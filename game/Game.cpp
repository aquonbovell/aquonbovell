#include "Game.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl;

Game::Game(std::string playerName, int Age) : Player(playerName, Age) {
	intro(Player::getName());
};

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

int Game::stringToInt(std::string input){
	try
			{
				return stoi(input);
			}
			catch(const std::exception& e)
			{
				return 20;
			}
}

int Game::stringToLevel(std::string level){
	std::transform(level.begin(), level.end(), level.begin(), ::toupper);
	if(level == "ROOKIE" || level == "R"){
		return 1;
	} else if (level == "TUFFTONG" || level == "T" )
	{
		return 2;
	} else if (level == "HARDSEED" || level == "H")
	{
		return 3;
	} else if (level == "QUIT" || level == "Q")
	{
		return 4;
	}
	else
	{
		return 5;
	}
}

int Game::stringToStatus(std::string status){
	std::transform(status.begin(), status.end(), status.begin(), ::toupper);
	if(status == "HINT" || status == "H"){
		return 1;
	} else if (status == "QUIT" || status == "Q" )
	{
		return 2;
	} else if (status == "CONTINUE" || status == "C")
	{
		return 3;
	}
	else
	{
		return 5;
	}
}

int Game::levelToHints(enum Level level){
	switch (level)
	{
	case Level::ROOKIE:
		return getRookieHint();
		break;
	case Level::TUFFTONG:
		return getTuffTongHint();
		break;
	case Level::HARDSEED:
		return getHardSeedHint();
		break;
	default:
		break;
	}
}

int Game::getRookieHint() const { return rookiehint; };

int Game::getTuffTongHint() const { return tufftonghint; };

int Game::getHardSeedHint() const { return hardseedhint; };

void Game::requestHint(enum Level level) {
	static int num_requests = 1;
	switch (level)
	{
	case ROOKIE:
			rookiehint -=1;
			decreaseScore(num_requests);
			num_requests++;
		break;
	case TUFFTONG:
			tufftonghint -=1;
			decreaseScore(num_requests);
			num_requests++;
		break;
	case HARDSEED:
			hardseedhint -=1;
			decreaseScore(num_requests);
			num_requests++;
		break;
	default:
		break;
	}
};

void Game::addHint(enum Level level){
	int rand_row_num = rand() % colums;
	int rand_row_col = rand() % colums;
	while (Game::isFilled(rand_row_num,rand_row_col)){
    rand_row_num = rand() % colums;
		rand_row_col = rand() % colums;
	}
	requestHint(level);
	playerArray[rand_row_num][rand_row_col] = solutionArray[rand_row_num][rand_row_col];
	std::cout<<"Hint added at row : "<<rand_row_num+1<< " and column : "<<rand_row_col+1 << std::endl;
}

int Game::getScore() const { return score; };

void Game::decreaseScore(int num_requests) { score -= pow(2, num_requests); };

void Game::createGame()
{
	srand(time(NULL));

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
			for (size_t k = 0; k < i; k++)
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

void Game::createCopy()
{
	for (size_t i = 0; i < rows; i++){
		for (size_t j = 0; j < rows; j++)
		{
			playerArray[i][j] = solutionArray[i][j];
		}
		
	}
};

void Game::removeSlots( enum Level level) {
	int remove_amount;
	switch (level)
	{
	case Level::ROOKIE:
		remove_amount = 10;
		break;
	case Level::TUFFTONG:
		remove_amount = 15;
		break;
	case Level::HARDSEED:
		remove_amount = 20;
		break;
	default:
		break;
	}
	int count(0), randnum(0);
	while (count != remove_amount) {
		for (auto& row : playerArray) {
			for (auto& element : row) {
				randnum = rand() % colums + 1;
				if ((randnum == element) && count < remove_amount) {
					element = 0;
					count++;
				}
			}
		}
	}
};

bool Game::isCompleted()
{
	//return true if all the slots are filled
	bool status = true;
	for (auto const row : playerArray)
	{
		for (auto const element : row)
			if (element == 0)
				status = false;
	}	
	return status;
};

bool Game::isInputCorrect(size_t row_num,size_t col_num,int number){
	if (number == solutionArray[row_num][col_num]){
		playerArray[row_num][col_num] = number;
		return true;
	}
	else
		return false;
}

bool Game::isFilled(size_t row_num,size_t col_num){
	//return true if playerArray[rn][cn] is filled
	return (playerArray[row_num][col_num] == 0)? false :true;
}

void Game::displayArray()
{
	cout << endl << "-------------------------" << endl;
	for (auto const& row : playerArray)
	{
		cout<<"| ";
		for (auto const& element : row)
		{
			cout << (element==0?'X':element) << " | ";
		}
			cout << endl << "-------------------------" << endl;
	}
};

void Game::reset() { rookiehint = 2; tufftonghint = 3; hardseedhint = 4; score = 20; };

void Game::congratulatoryMessage(){
	cout << "Congratulations!! " << getName() << " has won the game," << endl
			<< "and has scored " << getScore() << " points at Rookie level." << endl;
}

int Game::stringToEndgame(std::string endGame){
	std::transform(endGame.begin(), endGame.end(), endGame.begin(), ::toupper);
	if(endGame== "YES" || endGame == "YE" || endGame == "Y"){
		return 1;
	} else if (endGame == "NO" || endGame == "N" )
	{
		return 0;
	}
	else
	{
		return 5;
	}
}

void Game::endGameMessage(){
	std::cout << endl << "Game had ended.\n"<<getName() << " has obtained " << getScore()
			<< " points for this game.\n"<< "The solution is: " << endl;
	cout << endl << "-------------------------" << endl;
	for (auto const& row : solutionArray)
	{
		cout<<"| ";
		for (auto const& element : row)
		{
			cout << (element==0?'X':element) << " | ";
		}
			cout << endl << "-------------------------" << endl;
	}
};

void Game::endGame(){
	score = 0;
}