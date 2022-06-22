#include "Player.h"
#include <cmath>
#include <iostream>

using std::cout; using std::endl;

Player::Player(std::string playername) : name(playername), rookiehint(2), tufftonghint(3), hardseedhint(4), score(20) {
    Game::setGameArray(solutionBoard);
    Game::copyGameArray(solutionBoard,playersBoard);
    Game::intro(playername);
};

std::string Player::getName() const { return name; };

int Player::getScore() { return score; };

int Player::getRookieHint() const { return rookiehint; };

int Player::getTuffTongHint() const { return tufftonghint; };

int Player::getHardSeedHint() const { return hardseedhint; };

void Player::setHintsAndScore() { rookiehint = 2; tufftonghint = 3; hardseedhint = 4; score = 20; };

void Player::requestHint() { rookiehint -= 1; tufftonghint -= 1; hardseedhint -= 1; };

void Player::decreaseScore(int n) { score -= pow(2, n); };

void Player::endGame() { score = 0;	rookiehint = 0;	tufftonghint = 0;	hardseedhint = 0; };

void Player::displaySolutionBoard(){
    Game::displayArray(solutionBoard);
}
void Player::displayPlayersBoard(){
    Game::displayArray(playersBoard);
}

void Player::removeNumbers(int amount){
    Game::removeNumbers(playersBoard,amount);
}

bool Player::checkBoard(size_t rn,size_t cn ,size_t p){
    return Game::checkEntry(solutionBoard, playersBoard,rn, cn , p);
}
bool Player::checkIfBoardIsFilled(size_t rn,size_t cn){
    return Game::checkIfFilled(playersBoard,rn,cn);
}
void Player::giveAHint(size_t rn){
	int rand_row_num = rand() % colums;
	int rand_row_col = rand() % colums;
	while (Game::checkIfFilled(playersBoard,rand_row_num,rand_row_col)){
        rand_row_num = rand() % colums;
		rand_row_col = rand() % colums;
	}
	playersBoard[rand_row_num][rand_row_col]= solutionBoard[rand_row_num][rand_row_col];
	rn++;
	decreaseScore(rn);
    requestHint();
}

bool Player::checkPlayersBoard(){
    return Game::checkGameArray(playersBoard);
}