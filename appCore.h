#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QScreen>


class appCore : public QObject
{
    Q_OBJECT
public:
    appCore(QObject *parent = 0);

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendToQml(int count);
    void sendResolution(int width, int height);

public slots:
    // Слот для приёма данных из qml-интерфейса
    void receiveFromQml();

private:
    int count;  // Счетчик, которым будем оперировать
};

#endif // APPCORE_H
