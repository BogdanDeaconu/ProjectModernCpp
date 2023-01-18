#include "Lobby.h"

Lobby::Lobby(std::string owner, std::string player1, std::string player2, std::string player3, std::string player4, int isStarted)
{
    m_id = -1;
    m_owner = owner;
    this->player1 = owner;
    this->player2 = player2;
    this->player3 = player3;
    this->player4 = player4;
    m_isStarted = isStarted;
}

Lobby::~Lobby()
{
}

void Lobby::addPlayer(std::string player)
{
    if (player1 == "")
    {
        player1 = player;
    }
    else if (player2 == "")
    {
        player2 = player;
    }
    else if (player3 == "")
    {
        player3 = player;
    }
    else if (player4 == "")
    {
        player4 = player;
    }
}
using GamesStorage = decltype(createStorageGame(""));


