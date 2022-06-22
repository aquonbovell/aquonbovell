#include "Player.h"
#include<cmath>

Player::Player(std::string playername) : name(playername), rookiehint(2), tufftonghint(3), hardseedhint(4), score(20) {};

std::string Player::getName() const { return name; };

int Player::getScore() { return score; };

int Player::getRookieHint() const { return rookiehint; };

int Player::getTuffTongHint() const { return tufftonghint; };

int Player::getHardSeedHint() const { return hardseedhint; };

void Player::setHintsAndScore() { rookiehint = 2; tufftonghint = 3; hardseedhint = 4; score = 20; };

void Player::requestHint() { rookiehint -= 1; tufftonghint -= 1; hardseedhint -= 1; };

void Player::decreaseScore(int n) { score -= pow(2, n); };

void Player::endGame() { score = 0;	rookiehint = 0;	tufftonghint = 0;	hardseedhint = 0; };