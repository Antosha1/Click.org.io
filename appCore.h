#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>

class appCore : public QObject
{
    Q_OBJECT
public:
    explicit appCore(QObject *parent = 0);

signals:
    // Сигнал для передачи данных в qml-интерфейс
    void sendToQml(int count);

public slots:
    // Слот для приёма данных из qml-интерфейса
    void receiveFromQml();

private:
    int count;  // Счетчик, которым будем оперировать
};

#endif // APPCORE_H
