#include "player.h"

Player::Player()
{}

void Player::incScore()
{
    m_currScore++;
}

void Player::changeScore(int score)
{
    m_currScore = score;
}

int Player::getScore() const
{
    return m_currScore;
}
