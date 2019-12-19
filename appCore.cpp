#include "appCore.h"

appCore::appCore(QObject *parent)
    : QObject(parent)
{

    count = 0;
}

void appCore::receiveFromQml()
{
    count++;
    emit sendToQml(count);
}
/*
void appCore::sendResolution(int width, int height)
{
    count++;
    emit sendToQml(count);
}
*/
