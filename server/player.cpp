#include "player.h"

Player::Player(QTcpSocket *socket)
    :m_socket(socket)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &Player::slotMessageFromPlayer);
    connect(m_socket, &QTcpSocket::disconnected, this, &Player::slotClientDisconnected);
}

void Player::sendToPlayer(QByteArray array)
{
    m_socket->write(array);
}

QByteArray Player::getPlayerMessage()
{
    return m_data;
}

QHostAddress Player::getIp()
{
    return m_socket->peerAddress();
}

void Player::slotMessageFromPlayer()
{
    m_data = m_socket->readAll();
    QDataStream in(m_data);
    in.setByteOrder(QDataStream::LittleEndian); //< Set the proper byte order
    quint8 messageType; //< The result you want
    in >> messageType;
    if (m_data.size() > 0)

        switch (messageType)
    {
    case 0:
        in >> m_nickName;
        searchingGame(this);
        break;
    case 1:
        stopSearhingGame(this);
        break;
    case 2:
        in >> m_currScore;
        gotScore(this, m_currScore);
        break;
    case 3:
        in >> m_currScore;
        qDebug() << "got last score " + QString("%1").arg(m_currScore);
        lastScore(this, m_currScore);
    }
}

void Player::slotClientDisconnected()
{
    m_socket->close();
    deletePlayer(this);
}

/*
void player::slotServerRead()
{
    while(m_socket->bytesAvailable()>0)
    {
        QByteArray array = m_socket->readAll();

        m_socket->write(array);
    }
}
*/
