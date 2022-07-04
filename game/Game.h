//Game Header
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <array>
#include <string>

class Game : Player{
public:
	static const int colums{6};
	static const int rows{6};
	enum Status
	{
		WON,
		LOST,
		CONTINUE,
		QUIT,
		RETRY,
		END,
		UNDEFINED
	};

	enum Level
	{
		ROOKIE,
		TUFFTONG,
		HARDSEED
	};
	//intro
	void intro(std::string name);
	int stringToLevel(std::string level);
	// hints
	int getRookieHint() const;
	int getTuffTongHint() const;
	int getHardSeedHint() const;
	void requestHint(enum Level level);
	void addNumberHint(size_t rn, enum Level level);
	void giveAHint(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn ,size_t p);
	//score
	int getScore() const;
	void decreaseScore(int n);
	//set arrays
	void createCopy(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray);
	void createGame(std::array <std::array< int,colums>, rows>& solutionArray);
	void removeSlots(std::array <std::array< int,colums>, rows>& Array, int amount);
	void removeNumbers(int);	
	//check arrays
	bool checkBoard(size_t rn,size_t cn ,size_t p);
	bool checkIfBoardIsFilled(size_t rn,size_t cn);
	bool isCompleted(std::array <std::array< int,colums>, rows>& playerArray);
	bool checkPlayersBoard();
	bool isInputCorrect(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn ,size_t p);
	bool checkIfFilled(std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn);
	//display arrays
	void displayArray(std::array <std::array< int,colums>, rows>& Array);
	//reset score and hints
	void setHintsAndScore();
  //terminate game
	int Game::stringToEndgame(std::string endGame);
	void endGame();

private:
	int score, tufftonghint, hardseedhint, rookiehint;
	std::array <std::array< int,colums>, rows>& playerArray;
	std::array <std::array< int,colums>, rows>& solutionArray;

};
#endif