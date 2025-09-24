#include "Player.h"

Player::Player(std::unique_ptr<BaseClass> characterClass)
    : characterClass_(std::move(characterClass))
{
}

Player::~Player() = default;
