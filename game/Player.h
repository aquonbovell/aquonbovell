//Player Class
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{

public:
	Player(std::string playerName = "Player1", int Age = 12);
	std::string getName() const;
	int getAge() const;
private:
	std::string name;
	int age;
};
#endif