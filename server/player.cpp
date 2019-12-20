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
        searchingGame(this);
        break;
    case 1:
        stopSearhingGame(this);
        break;
    case 2:
        in >> m_currScore;
        gotScore(this, m_currScore);
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
