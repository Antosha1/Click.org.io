#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QTimer>
#include <QDataStream>
#include "player.h"

const int sessionsPlayersNumber = 4;
const int sessionTime = 20000;
const int sendingTime = 100;

class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr);
    void incMyScore();
    int getMyScore();
    void setMyNickName(QString NickName)
    {m_players[0].setNickName(NickName);}
    QString getMyNickName()
    {return m_players[0].getNickName();}
signals:
    void sendToServer(QByteArray array);
    void sendScoresToQML(int score1, int score2, int score3);
    void sendWinner (Player winner);
    void sendTime(float time);

public slots:
    void startGame(qint8 myNumber, QList<QString> playersNicks);
    void updateScores(QList<int> Scores, bool last);

private slots:
    void endSession();
    void sendMyScore();

private:
    QTimer m_mainTimer;
    QTimer m_smallTimer;
    bool m_gameStarted;
    qint8 m_myNumber;
    QString m_myNickName;
    Player m_players[sessionsPlayersNumber];
};

#endif // SESSION_H
