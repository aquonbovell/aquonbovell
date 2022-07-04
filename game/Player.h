//Player Class
#ifndef PLAYER_H
#define PLAYER_H

class Player{

public:
	Player(std::string playerName = "Player1");
	std::string getName() const;
private:
	std::string name;
};
#endif