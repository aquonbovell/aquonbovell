//Player Class
#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"

class Player : private Game{

	std::array<std::array<int, Game::colums>,Game::rows> playersBoard;
	std::array<std::array<int, Game::colums>,Game::rows> solutionBoard;
	std::string name; int score, tufftonghint, hardseedhint, rookiehint;
public:
	Player(std::string);
	std::string getName() const;
	int getScore();
	int getRookieHint() const;
	int getTuffTongHint() const;
	int getHardSeedHint() const;
	void setHintsAndScore();
	void requestHint();
	void decreaseScore(int n);
	void endGame();
	void displaySolutionBoard();
	void displayPlayersBoard();
	using Game::stringToGame;
	using Game::stringToGameEnd;
	void removeNumbers(int);
	bool checkBoard(size_t rn,size_t cn ,size_t p);
	bool checkIfBoardIsFilled(size_t rn,size_t cn);
	void giveAHint(size_t rn);
	bool checkPlayersBoard();
};
#endif