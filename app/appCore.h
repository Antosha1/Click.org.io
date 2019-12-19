#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QScreen>
#include "player.h"

class appCore : public QObject
{
    Q_OBJECT
public:
    explicit appCore(QObject *parent = 0);

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendStringToQML(QString string);
    void sendResolution(int width, int height);
    void sendMyScoreToQML(int score);
    void sendPlayer1ScoreToQML(int score);
    void sendPlayer2ScoreToQML(int score);
    void sendPlayer3ScoreToQML(int score);

public slots:
    // Слот для приёма данных из qml-интерфейса
    void qmlButtonClicked();

private:
    player player0;
    player player1;
    player player2;
    player player3;

};

#endif // APPCORE_H
