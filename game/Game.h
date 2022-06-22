//Game Header
#ifndef GAME_H
#define GAME_H
#include <array>
#include <string>

class Game {
public:
	static const int colums{6};
	static const int rows{6};
	void setGameArray(std::array <std::array< int,colums>, rows>& solutionArray);
	void copyGameArray(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray);
	void removeNumbers(std::array <std::array< int,colums>, rows>& Array, int amount);
	void displayArray(std::array <std::array< int,colums>, rows>& Array);
	bool checkGameArray(std::array <std::array< int,colums>, rows>& playerArray);
	int stringToGame(std::string);
	void intro(std::string name);
	int Game::stringToGameEnd(std::string endGame);

	bool checkEntry(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn ,size_t p);
	bool checkIfFilled(std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn);
	void giveAHint(std::array<std::array< int,colums>, rows>& solutionArray,std::array <std::array< int,colums>, rows>& playerArray,size_t rn,size_t cn ,size_t p);
};
#endif