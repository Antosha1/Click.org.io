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

}

void appCore::qmlButtonClicked()
{
    m_session.incMyScore();
    emit sendMyScoreToQML(m_session.getMyScore());
}

void appCore::startButtonClicked(QString nickName)
{
    m_session.setMyNickName(nickName);
    m_tcpClient.connectToServer();
}
///
void appCore::sendScoresToQML(int score1, int score2, int score3)
{
    sendPlayer1ScoreToQML(score1);
    sendPlayer2ScoreToQML(score2);
    sendPlayer3ScoreToQML(score3);
}

void appCore::startSessionManager(int myNumber)
{
    sendMyNickName("Me");
    sendPlayer1NickName("1");
    sendPlayer2NickName("2");
    sendPlayer3NickName("3");
    sendScoresToQML(0,0,0);
    startSession();
    m_session.startGame(myNumber);
}

void appCore::endSessionManager()
{
    //results
    m_tcpClient.disconnect();
}

void appCore::getWinner(Player winner)
{
    sendWinnerNickName(winner.getNickName());
    sendWinnerScore(winner.getScore());
    endSession();
}


