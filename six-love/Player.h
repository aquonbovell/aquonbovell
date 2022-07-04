//Player Class
#ifndef PLAYER_H
#define PLAYER_H
#include <array>
#include <string>

class Player{

private:
	std::string name;static const int colums{6};
	static const int rows{6};
	std::array<std::array<int, colums>, rows> playersBoard;
	std::array<std::array<int, colums>, rows> solutionBoard;
	int score,rookiehint,tufftonghints, hardseedhints;
public:
	Player(std::string);
	std::string getName() const;
	int getScore();
	int getRookieHint() const;
	int getTuffTongHint() const;
	int getHardSeedHint() const;
	void setRookieHintAndScore();
	void setTuffTongHintsAndScore();
	void setHardSeedHintsAndScore();
	void requestRookieHint();
	void requestTuffTongHint();
	void requestHardSeedHint();
	void decreaseScore(int n);
	void endRookieGame();
	void endTuffTongGame();
	void endHardSeedGame();

	void intro(const std::string &name);
	void setArray(std::array<std::array<int, colums>, rows> &Array);
	void copyArray(std::array<std::array<int, colums>, rows> &solutionArray, std::array<std::array<int, colums>, rows> &playerArray);
	void removeNumbers(std::array<std::array<int, colums>, rows> &Array, int amount);
	void displayArray(std::array<std::array<int, colums>, rows> &Array);
	bool isCompleted(std::array<std::array<int, colums>, rows> &Array) const;
	bool isCorrect(std::array<std::array<int, colums>, rows> &solutionArray, std::array<std::array<int, colums>, rows> &playerArray, size_t rn, size_t cn, int p) const;
	bool isFilled(std::array<std::array<int, colums>, rows> &playerArray, size_t rn, size_t cn) const;	
	void giveAHint(size_t rn);
	int choice(std::string &level) const;
	int gameChoice(std::string &endGame) const;
};
#endif