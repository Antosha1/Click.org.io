#include "sessionsManager.h"

SessionsManager::SessionsManager(QObject *parent)
    : QObject(parent)
{

}

void SessionsManager::addSleepingPlayer(Player * player)
{
    m_sleepingPlayers.insert(player);
    connect(player, &Player::searchingGame, this, &SessionsManager::addSearchingPlayer);
    connect(player, &Player::stopSearhingGame, this, &SessionsManager::stopSearchingPlayer);
}

void SessionsManager::removePlayer(Player * player)
{
    if (m_sleepingPlayers.find(player)!=m_sleepingPlayers.end())
        m_sleepingPlayers.erase(m_sleepingPlayers.find(player));
    if (m_waitingPlayers.find(player)!=m_waitingPlayers.end())
        m_waitingPlayers.erase(m_waitingPlayers.find(player));
    if (m_sessionPlayers.find(player)!=m_sessionPlayers.end())
    {
        m_sessionPlayers.erase(m_sessionPlayers.find(player));
        Session * session = *(m_playersSession.find(player));
        session->playerDisconnect(player);
    }
}

void SessionsManager::addSearchingPlayer(Player * player)
{
    if (m_sleepingPlayers.find(player)!=m_sleepingPlayers.end())
    {
        m_sleepingPlayers.erase(m_sleepingPlayers.find(player));
        m_waitingPlayers.insert(player);
        if (m_waitingPlayers.size() >= sessionsPlayersNumber)
        {
            Session * session = new Session(this);
            connect(session, &Session::endSession, this, &SessionsManager::endSession);
            m_sessions.insert(session);
            auto it = m_waitingPlayers.begin();
            for (int i = 0; i < sessionsPlayersNumber; ++i)
            {
                Player *currPlayer = *it;
                it = m_waitingPlayers.erase(it);
                session->addPlayer(currPlayer);
                m_sessionPlayers.insert(currPlayer);
                m_playersSession.insert(currPlayer, session);
            }
            session->startSession();
        }
    }
}

void SessionsManager::stopSearchingPlayer(Player * player)
{
    if (m_waitingPlayers.find(player)!=m_waitingPlayers.end())
    {
        m_waitingPlayers.erase(m_waitingPlayers.find(player));
        m_sleepingPlayers.insert(player);
    }
}

void SessionsManager::endSession(Session * session)
{
    foreach (auto player, session->getPlayers())
    {
        m_sessionPlayers.erase(m_sessionPlayers.find(player));
        m_sleepingPlayers.insert(player);
        m_playersSession.erase(m_playersSession.find(player));
    }
    m_sessions.erase(m_sessions.find(session));
    delete session;
}
