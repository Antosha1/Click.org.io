#ifndef PLAYER_H
#define PLAYER_H

#include<QString>

class Player
{
public:
    Player(QString nickName, int score);
    void incScore();
    void incScore(int inc);
    int getScore() const;
private:
    QString m_nickName;
    int m_currScore;

};

#endif // PLAYER_H
