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

public slots:
    void recievedScore(Player* player, int Score);
    void recievedLastScore(Player* player, int Score);

signals:
    void endSession(Session *session);

private:
        void sendCurrentScore(bool last);
        void sendLastScore();

    QSet<Player *> m_players;
    QHash <Player*, int> m_Scores;
    int m_playersStillInGame;
};

#endif // SESSION_H
