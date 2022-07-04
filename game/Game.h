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
	std::array <std::array< int,colums>, rows> solutionArray;
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
	void createGame(std::array <std::array< int,colums>, rows>& array);
	void createCopy(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray);
	void removeSlots(std::array <std::array< int,colums>, rows>& array, int remove_amount);	
	
	//check arrays
	bool isCompleted(std::array <std::array< int,colums>, rows>& array);
	bool isInputCorrect(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray,size_t row_num,size_t col_num,int number);
	bool isFilled(std::array <std::array< int,colums>, rows>& array,size_t row_num,size_t col_num);
	
	//display arrays
	void displayArray(std::array <std::array< int,colums>, rows>& array);
	
	//reset score and hints
	void reset();
  
	//terminate game
	int stringToEndgame(std::string endGame);
	void endGame();

private:
	int score, tufftonghint, hardseedhint, rookiehint;
};
#endif