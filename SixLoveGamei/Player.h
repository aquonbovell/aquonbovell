//Player Class
#include<string>

class Player {
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
};