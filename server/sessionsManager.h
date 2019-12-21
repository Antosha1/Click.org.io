#ifndef SESSIONSMANAGER_H
#define SESSIONSMANAGER_H

#include <QObject>
#include "player.h"
#include "session.h"

const int sessionsPlayersNumber = 4;

class SessionsManager : public QObject
{
    Q_OBJECT
public:
    explicit SessionsManager(QObject *parent = nullptr);
    void addSleepingPlayer(Player * player);
    void removePlayer (Player * player);
signals:

public slots:
    void addSearchingPlayer(Player * player);
    void stopSearchingPlayer(Player * player);
    void endSession (Session * session);

private:
    QSet <Player *> m_sleepingPlayers;
    QSet <Player *> m_sessionPlayers;
    QSet <Player *> m_waitingPlayers;
    QSet <Session *> m_sessions;
    QHash <Player *, Session *> m_playersSession;
};

#endif // SESSIONSMANAGER_H
