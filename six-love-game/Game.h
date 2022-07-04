//Game Header
class Game {
public:
	void setGameArray(int short A[][6]);
	void copyGameArray(int short A[][6], int short B[][6]);
	void removeNumbers(int short A[][6], int short amount);
	void displayArray(int short A[][6]);
	bool checkGameArray(int short A[][6]);
	int stringToGame(std::string);
};