#include "player.h"

player::player(QString nickName, int score)
    : m_nickName(nickName), m_currScore(score)
{}

void player::incScore()
{
    m_currScore++;
}

void player::incScore(int inc)
{
    m_currScore+=inc;
}

int player::getScore() const
{
    return m_currScore;
}
