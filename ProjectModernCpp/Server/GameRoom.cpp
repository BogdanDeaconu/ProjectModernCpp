#include "GameRoom.h"

GameRoom::GameRoom():
    gameHasBegun(false)
{
}

GameRoom::GameRoom(int id, RoomInfo roomInfo, Player player)
{
    this->m_roomInfo = roomInfo;
    this->m_roomInfo.id = id;
    this->m_roomInfo.isActive = true;
    this->m_players.push_back(player);
    this->gameHasBegun = false;
}

GameRoom::~GameRoom()
{
    this->m_players.clear();
}

bool GameRoom::addPlayer(const Player& player)
{
    if (this->m_roomInfo.isActive && this->m_players.size() < this->m_roomInfo.maxPlayers)
    {
        this->m_players.push_back(player);
        return true;
    }
    return false;
}

bool GameRoom::removePlayer(const Player& player)
{
    if (this->m_roomInfo.isActive)
    {
        for (int i = 0; i < this->m_players.size(); i++)
        {
            if (this->m_players[i].GetName() == player.GetName())
            {
                this->m_players.erase(this->m_players.begin() + i);
                return true;
            }
        }
    }
    return false;
}

std::vector<Player> GameRoom::getPlayers() const
{
    return this->m_players;
}

RoomInfo GameRoom::getRoomInfo() const
{
    return this->m_roomInfo;
}

std::vector<std::string> GameRoom::getAllUsernames()
{
    std::vector<std::string> usernames;
    for (int i = 0; i < this->m_players.size(); i++)
    {
        usernames.push_back(this->m_players[i].GetName());
    }
    return usernames;
}


