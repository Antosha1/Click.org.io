#include "appCore.h"

appCore::appCore(QObject *parent)
    : QObject(parent),
      player0("Me", 0),
      player1("1", 0),
      player2("2", 0),
      player3("3", 0)
{}

void appCore::QmlButtonClicked()
{
    player0.incScore();
    emit sendMyScoreToQML(player0.getScore());
}

/*
void appCore::sendResolution(int width, int height)
{
    count++;
    emit sendToQml(count);
}
*/
