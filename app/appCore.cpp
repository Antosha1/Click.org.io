#include "appCore.h"

appCore::appCore(QObject *parent)
    : QObject(parent)
{
    connect(&m_tcpClient,&TcpClient::gameFound,this,&appCore::startSessionManager);
    connect(&m_session,&Session::sendScoresToQML,this, &appCore::sendScoresToQML);
    connect(&m_session,&Session::sendToServer,&m_tcpClient, &TcpClient::sendToServer);
    connect(&m_tcpClient, &TcpClient::gotScores,&m_session,&Session::updateScores);
    connect(&m_session,&Session::sendWinner,this, &appCore::getWinner);
    connect(&m_session,&Session::sendTime,this, &appCore::getTime);
    connect(&m_tcpClient,&TcpClient::sendServerIp,this, &appCore::sendIp);

}

void appCore::qmlButtonClicked()
{
    m_session.incMyScore();
    emit sendMyScoreToQML(m_session.getMyScore());
}

void appCore::startButtonClicked(QString nickName)
{
    m_session.setMyNickName(nickName);
    m_tcpClient.connectToServer(nickName);
}
///
void appCore::sendScoresToQML(int score1, int score2, int score3)
{
    sendPlayer1ScoreToQML(score1);
    sendPlayer2ScoreToQML(score2);
    sendPlayer3ScoreToQML(score3);
}

void appCore::startSessionManager(qint8 myNumber, QList<QString> Nicks)
{
    QList<QString> playersNicks;
    for (int i = 0; i<sessionsPlayersNumber;++i)
        if (i!= myNumber)
        {
            playersNicks.append(Nicks[i]);
        }
    sendMyNickName(m_session.getMyNickName());
    sendPlayer1NickName(playersNicks[0]);
    sendPlayer2NickName(playersNicks[1]);
    sendPlayer3NickName(playersNicks[2]);
    sendScoresToQML(0,0,0);
    startSession();
    m_session.startGame(myNumber, playersNicks);
}

void appCore::endSessionManager()
{
    //results
    m_tcpClient.disconnect();
}

void appCore::getWinner(Player winner)
{
    endSession();
    sendWinnerNickName(winner.getNickName());
    sendWinnerScore(winner.getScore());
    m_tcpClient.disconnectFromServer();

}


