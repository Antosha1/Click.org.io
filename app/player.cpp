#include "player.h"

Player::Player(QString nickName, int score)
    : m_nickName(nickName), m_currScore(score)
{}

void Player::incScore()
{
    m_currScore++;
}

void Player::incScore(int inc)
{
    m_currScore+=inc;
}

int Player::getScore() const
{
    return m_currScore;
}
