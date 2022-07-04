#include "Player.h"

Player::Player(std::string playername, int Age) : name{playername}, age{Age}{};

std::string Player::getName() const { return name; };

int Player::getAge() const { return age; };