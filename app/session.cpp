#include "session.h"

Session::Session(QObject *parent)
    : QObject(parent)
{
    connect(&m_mainTimer, &QTimer::timeout, this, &Session::endSession);
    connect(&m_smallTimer, &QTimer::timeout, this, &Session::sendMyScore);
}

void Session::incMyScore()
{
    if (m_gameStarted)
        m_players[0].incScore();
}

int Session::getMyScore()
{
    return m_players[0].getScore();
}

void Session::startGame(qint8 myNumber, QList<QString> playersNicks)
{
    m_myNumber = myNumber;
    m_players[0].changeScore(0);
    m_players[1].setNickName(playersNicks[0]);
    m_players[2].setNickName(playersNicks[1]);
    m_players[3].setNickName(playersNicks[2]);
    m_gameStarted = true;
    m_mainTimer.start(sessionTime);
    m_mainTimer.setSingleShot(true);
    m_smallTimer.start(sendingTime);

    //
}

void Session::sendMyScore()
{
    if (m_gameStarted)
    {
        float time = sessionTime - m_mainTimer.remainingTime();
        time/= sessionTime;
        sendTime(time);
        m_smallTimer.start(sendingTime);

        QByteArray message;
        QDataStream in(&message, QIODevice::WriteOnly);
        in.setByteOrder(QDataStream::LittleEndian);
        quint8 messageType = 2;
        in << messageType;
        in<<getMyScore();
        sendToServer(message);
    }
}

void Session::updateScores(QList<int> Scores, bool last)
{
    QList<int> playersScores;
    for (int i = 0; i<sessionsPlayersNumber;++i)
        if (i!= m_myNumber)
        {
            playersScores.append(Scores[i]);
        }
    for (int i = 1; i<sessionsPlayersNumber;++i)
        m_players[i].changeScore(playersScores[i-1]);
    sendScoresToQML(playersScores[0],playersScores[1],playersScores[2]);
    if(last)
    {
        Player winner = m_players[0];
        for (int i = 1; i<sessionsPlayersNumber;++i)
            if (m_players[i].getScore()>winner.getScore())
                winner = m_players[i];
        sendWinner(winner);
    }
}

void Session::endSession()
{
    m_gameStarted = false;
    m_smallTimer.stop();
    QByteArray message;
    QDataStream in(&message, QIODevice::WriteOnly);
    in.setByteOrder(QDataStream::LittleEndian);
    quint8 messageType = 3;
    in << messageType;
    in<<getMyScore();
    sendToServer(message);
}

