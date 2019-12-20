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

void TcpClient::connectToServer()
{
    m_socket.connectToHost("127.0.0.1",12345);
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
    if (m_data.size() > 0)

        switch (messageType)
    {
    case 0:
        int myNumber;
        in >> myNumber;
        gameFound(myNumber);
        break;
    case 1:
        break;
    case 2:
        while (!in.atEnd())
        {
            in >> score;
            Scores.append(score);
        }
        gotScores(Scores);
        break;
    case 3:
        while (!in.atEnd())
        {
            in >> score;
            Scores.append(score);
        }
        lastScores(Scores);
        }
}

void TcpClient::serverConnected()
{

}

void TcpClient::connectionDisplayError(QAbstractSocket::SocketError socketError)
{

}

void TcpClient::serverDisconnected()
{

}
