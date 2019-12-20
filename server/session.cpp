#include "session.h"

Session::Session(QObject *parent)
    : QObject(parent)
{}

void Session::playerDisconnect(Player *player)
{

}

void Session::addPlayer(Player *player)
{
    m_players.insert(player);
    m_Scores.insert(player, 0);
}

void Session::startSession()
{
    char n_player = 0;
    QByteArray message (2, n_player);
    foreach(auto player, m_players)
    {
        message[1] = n_player;
        n_player++;
        player->sendToPlayer(message);
    }
}

QSet<Player *> Session::getPlayers() const
{
    return m_players;
}

void Session::sendCurrentScore()
{
    QByteArray message;
    QDataStream in(&message, QIODevice::WriteOnly);
    in.setByteOrder(QDataStream::LittleEndian); //< Set the proper byte order
    quint8 messageType = 2; //< The result you want
    in << messageType;

}
