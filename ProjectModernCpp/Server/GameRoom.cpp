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


