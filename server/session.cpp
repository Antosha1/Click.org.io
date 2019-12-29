#include "session.h"

Session::Session(QObject *parent)
    : QObject(parent), m_playersStillInGame(0)
{}

void Session::playerDisconnect(Player *player)
{
    m_players.erase(m_players.find(player));
    m_playersStillInGame--;
}

void Session::addPlayer(Player *player)
{
    m_players.insert(player);
    m_Scores.insert(player, 0);
    connect(player,&Player::gotScore,this,&Session::recievedScore);
    connect(player,&Player::lastScore,this,&Session::recievedLastScore);
    m_playersStillInGame++;
}

void Session::startSession()
{
    char n_player = 0;
    QByteArray message (2, n_player);
    for (auto it = m_Scores.begin(); it!= m_Scores.end();++it )
    {
        message[1] = n_player;
        n_player++;
        it.key()->sendToPlayer(message);
    }
}

QSet<Player *> Session::getPlayers() const
{
    return m_players;
}

void Session::recievedScore(Player *player, int Score)
{
    m_Scores[player] = Score;
    sendCurrentScore(false);
}

void Session::recievedLastScore(Player *player, int Score)
{
    m_Scores[player] = Score;
    m_playersStillInGame--;
    if (m_playersStillInGame <= 0)
    {
        sendCurrentScore(true);
        emit endSession(this);
    }
    else
    {
        sendCurrentScore(false);
    }
}

void Session::sendCurrentScore(bool last)
{
    QByteArray message;
    QDataStream in(&message, QIODevice::WriteOnly);
    in.setByteOrder(QDataStream::LittleEndian);
    quint8 messageType;
    if (last)
    {
        messageType= 3;
    }
    else
        messageType = 2;
    in << messageType;
    foreach (int score, m_Scores)
    {
        in<<score;
    }
    if (last)
    {
        QString lastString = "last message sent";
        foreach (int score, m_Scores)
        {
            lastString +=  ' ' + QString("%1").arg(score);
        }

        qDebug() << lastString;
    }
    foreach(auto player, m_players)
    {
        player->sendToPlayer(message);
    }
}

