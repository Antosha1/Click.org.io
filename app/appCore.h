#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QScreen>

#include "tcpClient.h"
#include "session.h"

class appCore : public QObject
{
    Q_OBJECT
public:
    explicit appCore(QObject *parent = 0);

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendResolution(int width, int height);
    void startSession();
    void endSession();
    void sendMyScoreToQML(int score);
    void sendPlayer1ScoreToQML(int score);
    void sendPlayer2ScoreToQML(int score);
    void sendPlayer3ScoreToQML(int score);
    void sendMyNickName(QString nickName);
    void sendPlayer1NickName(QString nickName);
    void sendPlayer2NickName(QString nickName);
    void sendPlayer3NickName(QString nickName);
    void sendWinnerNickName(QString nickName);
    void sendWinnerScore(int score);
    void sendTime(float time);
    void sendServerIp(QString ipAddr);
public slots:
    // Слоты для приёма данных из qml-интерфейса
    void qmlButtonClicked();
    void startButtonClicked(QString nickName);
    //C++ slots
    void sendScoresToQML(int score1, int score2, int score3);
    void startSessionManager(qint8 myNumber);
    void endSessionManager();
    void getWinner (Player winner);
    void sendIp(QString ipAddr)
    {
        sendServerIp(ipAddr);
    }
    void getTime (float time)
    {
        sendTime(time);
    }
private:
    TcpClient m_tcpClient;
    Session m_session;

};

#endif // APPCORE_H
