#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QtNetwork>

class Player: public QObject
{
    Q_OBJECT
public:
    explicit Player(QTcpSocket *socket);
    void sendToPlayer(QByteArray array);
    QByteArray getPlayerMessage();

public slots:
    void slotMessageFromPlayer();
    void slotClientDisconnected();

private:
    QTcpSocket *m_socket;
    QString m_nickName;
    int m_currScore;
    QByteArray m_data;

signals:
    void searchingGame(Player*);
    void stopSearhingGame(Player*);
    void gotScore(Player*, int score);
    void deletePlayer(Player* Player);

};

#endif // PLAYER_H
