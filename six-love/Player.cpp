//Player implementation
#include "Player.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Player::Player(std::string playername) : name{playername} {
    setArray(solutionBoard);
    copyArray(solutionBoard,playersBoard);
    intro(playername);
};

std::string Player::getName() const { return name; };

int Player::getScore() { return score; };

int Player::getRookieHint() const { return rookiehint; };

int Player::getTuffTongHint() const { return tufftonghints; };

int Player::getHardSeedHint() const { return hardseedhints; };

void Player::setRookieHintAndScore() { rookiehint = 2; score = 20; };

void Player::setTuffTongHintsAndScore() { tufftonghints = 2; score = 20; };

void Player::setHardSeedHintsAndScore() { hardseedhints = 2; score = 20; };

void Player::requestRookieHint() { rookiehint -= 1; };

void Player::requestTuffTongHint() { tufftonghints -= 1; };

void Player::requestHardSeedHint() { hardseedhints -= 1; };

void Player::decreaseScore(int n) { score -= pow(2, n); };

void Player::endRookieGame() { score = 0;	rookiehint = 0;};

void Player::endTuffTongGame() { score = 0;	tufftonghints = 0;};

void Player::endHardSeedGame() { score = 0;	hardseedhints = 0;};

// void Player::giveAHint(size_t rn) {
// 	int rand_row_num = rand() % colums;
// 	int rand_row_col = rand() % colums;
// 	while (isFilled(playersBoard,rand_row_num,rand_row_col)){
//         rand_row_num = rand() % colums;
// 		rand_row_col = rand() % colums;
// 	}
// 	playersBoard[rand_row_num][rand_row_col]= solutionBoard[rand_row_num][rand_row_col];
// 	++rn;
// 	decreaseScore(rn);
//     requestHint();
// }

void Player::setArray(std::array <std::array< int,colums>, rows> & Array)
{
	srand(time(NULL));

	for (size_t i = 0; i < Array.size(); ++i)
	{
	repeat:
		for (size_t j = 0; j < Array.size(); ++j)
		{
			Array[i][j] = rand() % colums + 1;

			for (size_t h = 0; h < j; ++h)
			{
				while (Array[i][j] == Array[i][h])
				{
					Array[i][j] = rand() % colums + 1;
					goto repeat;
				}
			}
			for (size_t k = 0; k < i; ++k)
			{
				while (Array[i][j] == Array[k][j])
				{
					Array[i][j] = rand() % colums + 1;
					goto repeat;
				}
			}
		}
	}
};

void Player::copyArray(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray)
{
	std::copy(std::begin(solutionArray),std::end(solutionArray),std::begin(playerArray));
};

void Player::removeNumbers(std::array <std::array< int,colums>, rows>& Array, int amount) {
	int count{0}, randnum{0};
	
	while (count != amount) {
		
		for (auto& row : Array) {
			for (auto& element : row) {
				randnum = rand() % colums + 1;
				if ((randnum == element) && count < amount) {element = 0;	count++;}
			}
		}
	}
};

void Player::displayArray(std::array <std::array< int,colums>, rows>& Array)
{
	std::ostringstream output;
	output << "\n-------------------------\n";
	for (auto const& row : Array)
	{
		output<<"| ";
		for (auto const& element : row)
		{
			output << element << " | ";
		}
			output << "\n-------------------------\n";
	}
	std::cout << output.str();
};

bool Player::isCompleted(std::array <std::array< int,colums>, rows>& playerArray) const
{
	bool game;
	for (auto const row : playerArray)
	{
		for (auto const element : row)
			game = { (element == 0) ? false : true};
	}
	return game;
};

int Player::choice(std::string& level) const {

	std::transform(level.begin(), level.end(), level.begin(), ::toupper);

	if(level == "ROOKIE" || level == "R")
		return 20;
	else if (level == "TUFFTONG" || level == "T" )
		return 21;
	else if (level == "HARDSEED" || level == "H")
		return 22;
	else if (level == "QUIT" || level == "Q")
		return 50;
	else
		return 30;
}

void Player::intro(const std::string& name){
	std::ostringstream output;
	output << "\nHello "<< name<<" Welcome to the SIX LOVE game!!\n"
	<<"This game is played on a 6x6 grid with components ranging from 1 to 6.\n"
	<<"There can only be one instance of each integer in each row and column.\n\n"
	<<"There are three levels in this game:\n\t(1) Rookie \n\t(2) Tuff Tong \n\t(3) Hard Seed\n\n"
	<<"RULES:\nTo select a level, enter the initial letter of the requested level\n"
    <<"(i.e. 'r' or 'R' for Rookie) or the complete word.\n"
    <<"To play effectively, you must also enter a row number from 1 to 6 (inclusionary),\n"
	<<"but also a column number and your input, to fill the spaces that include zeros.\n"
	<<"You can exit the game at any time by typing the number '99' at any prompt.\n\n"
	<<"BUT DO NOT ENTER A NUMBER WHEN ASKING FOR A HINT; INSTEAD, ENTER THE LETTER \'Q\'.\n\n"
	<<"Rookie will only have one clue, Tuff Tong will only have two, and Hard Seed will only have three.\n"
	<<"If you request more than the amount given for each level, the game will finish and you will earn no points.\n\n"
	<<"Have fun with the game.!!\n\n";
	std::cout<<output.str();
}

bool Player::isCorrect(std::array<std::array< int,colums>, rows>& solutionArray, std::array <std::array< int,colums>, rows>& playerArray, size_t rownum,size_t colnum ,int num) const{
	if (num == solutionArray[rownum][colnum]){
		playerArray[rownum][colnum] = num;
		return true;
	}
	else
		return false;
};

bool Player::isFilled(std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn) const{
	return (playerArray[rn][cn] != 0)? true :false;
}

int Player::gameChoice(std::string& endGame) const{

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