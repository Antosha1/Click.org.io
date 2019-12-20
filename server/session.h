#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "player.h"

class Session : public QObject
{
    Q_OBJECT
public:
    Session(QObject *parent = nullptr);
    void playerDisconnect(Player * player);
    void addPlayer(Player * player);
    void startSession();
    QSet<Player *> getPlayers() const;
signals:
    void endSession(Session *session);

private:
        void sendCurrentScore();

    QSet<Player *> m_players;
    QHash <Player*, int> m_Scores;
};

#endif // SESSION_H
