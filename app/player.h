#ifndef PLAYER_H
#define PLAYER_H

#include<QString>

class Player
{
public:
    Player();
    void incScore();
    void changeScore(int score);
    int getScore() const;
    void setNickName(QString newName)
    {
        m_nickName = newName;
    }
    QString getNickName()
    {
        return m_nickName;
    }
private:
    QString m_nickName;
    int m_currScore;

};

#endif // PLAYER_H
