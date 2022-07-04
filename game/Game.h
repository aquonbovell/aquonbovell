//Game Header
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <array>

class Game : public Player{
public:
	static const int colums{6};
	static const int rows{6};
	std::array <std::array< int,colums>, rows> playerArray;
	
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
	Status status;
	enum Level
	{
		ROOKIE,
		TUFFTONG,
		HARDSEED
	};
	Level level;

	//contructor
	Game(std::string playerName = "Player1", int Age = 12);
	
	//intro
	void intro(std::string name);
	
	//level selection
	int stringToLevel(std::string level);
	
	// hints
	int getRookieHint() const;
	int getTuffTongHint() const;
	int getHardSeedHint() const;
	void requestHint(enum Level level);
	void addHint(enum Level level);
	
	//score
	int getScore() const;
	void decreaseScore(int num_requests);
	
	//set arrays
	void createGame();
	void createCopy();
	void removeSlots(int remove_amount);	
	
	//check arrays
	bool isCompleted();
	bool isInputCorrect(size_t row_num,size_t col_num,int number);
	bool isFilled(size_t row_num,size_t col_num);
	
	//display arrays
	void displayArray();
	
	//reset score and hints
	void reset();
  
	//terminate game
	int stringToEndgame(std::string endGame);
	void endGame();

private:
	int score, tufftonghint, hardseedhint, rookiehint;std::array <std::array< int,colums>, rows> solutionArray;
};
#endif