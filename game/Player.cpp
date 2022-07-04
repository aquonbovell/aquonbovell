#include "Player.h"
#include <string>

Player::Player(std::string playername) : name{playername}{};

std::string Player::getName() const { return name; };