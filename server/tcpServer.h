#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <player.h>
#include <sessionsManager.h>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

public slots:
    void slotNewConnection();
    void deletePlayer(Player * Player);

private:
    QSet<Player *> m_players;
    QTcpServer *m_TcpServer;
    SessionsManager m_manager;

};

#endif // TCPSERVER_H
