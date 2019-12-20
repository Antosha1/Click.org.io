#include "tcpServer.h"

#include <QDebug>
#include <QCoreApplication>

TcpServer::TcpServer(QObject *parent) : QObject(parent), m_players(QSet<Player*>())
{
    m_TcpServer = new QTcpServer(this);

    connect(m_TcpServer, &QTcpServer::newConnection, this, &TcpServer::slotNewConnection);

    if(!m_TcpServer->listen(QHostAddress::Any, 12345))
    {
        qDebug() << "server is not started";
    }
    else
    {
        qDebug() << "server is started";
    }
}

void TcpServer::slotNewConnection()
{

    Player* currPlayer =*(m_players.insert(new Player(m_TcpServer->nextPendingConnection())));
    connect(currPlayer, &Player::deletePlayer, this, &TcpServer::deletePlayer);
    m_manager.addSleepingPlayer(currPlayer);
    qDebug() << "player connected";
    foreach (auto player, m_players) {
        player->sendToPlayer("Hello, World!!! I am echo server!\r\n");
    }

}

void TcpServer::deletePlayer(Player *player)
{
    m_players.erase(m_players.find(player));
    m_manager.removePlayer(player);
    qDebug() << "player disconnected";
    delete player;
}
