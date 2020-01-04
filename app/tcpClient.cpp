#include "tcpClient.h"

TcpClient::TcpClient(QObject *parent)
    : QObject(parent)
{
    connect(&m_socket, &QTcpSocket::readyRead, this, &TcpClient::slotMessageFromServer);
    connect(&m_socket, &QTcpSocket::disconnected, this, &TcpClient::serverDisconnected);
    connect(&m_socket, &QTcpSocket::connected, this, &TcpClient::serverConnected);
    connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(connectionDisplayError(QAbstractSocket::SocketError)));
}

void TcpClient::sendToServer(QByteArray array)
{
    m_socket.write(array);
}

void TcpClient::connectToServer(QString nickName)
{
    m_nickName = nickName;
    m_socket.connectToHost("192.168.1.12",12345);//80.87.146.232
}

void TcpClient::slotMessageFromServer()
{
    m_data = m_socket.readAll();
    QDataStream in(m_data);
    in.setByteOrder(QDataStream::LittleEndian);
    quint8 messageType;
    in >> messageType;
    int score;
    QList <int> Scores;
    QString nickName;
    QList <QString> Nicks;
    if (m_data.size() > 0)

    switch (messageType)
    {
    case 0:
        qint8 myNumber;
        in >> myNumber;
        for (int i = 0; i <4; i++)
        {
            in >> nickName;
            Nicks.append(nickName);
        }
        gameFound(myNumber, Nicks);
        break;
    case 1:
        break;
    case 2:
        for (int i = 0; i <4; i++)
        {
            in >> score;
            Scores.append(score);
        }
        gotScores(Scores, false);
        break;
    case 3:
        for (int i = 0; i <4; i++)
        {
            in >> score;
            Scores.append(score);
        }
        gotScores(Scores, true);
    }
}

void TcpClient::serverConnected()
{
    QByteArray message;
    QDataStream in(&message, QIODevice::WriteOnly);
    in.setByteOrder(QDataStream::LittleEndian);
    quint8 messageType = 0;
    in << messageType;
    in << m_nickName;
    sendToServer(message);
    sendServerIp(getServerIp());
}

void TcpClient::connectionDisplayError(QAbstractSocket::SocketError socketError)
{

}

void TcpClient::serverDisconnected()
{

}
