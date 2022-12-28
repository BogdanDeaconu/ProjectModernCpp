#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

struct RoomInfo
{
    int id;
    std::string name;
    int maxPlayers;
    int timeForQuestion;
    int numberOfQuestions;
    std::string boardDimensions;
    int isActive;

    std::string toString()
    {
        return std::to_string(id) + "," + name + "," +
            std::to_string(maxPlayers) + "," +
            std::to_string(timeForQuestion) + "," +
            std::to_string(numberOfQuestions) + "," +
            boardDimensions + "," +
            std::to_string(isActive);
    }

};

class GameRoom
{
public:
    GameRoom();
    GameRoom(int id, RoomInfo roomInfo, Player player);
    ~GameRoom();
    
private:
    bool gameHasBegun;
    std::vector<Player> m_players;
    RoomInfo m_roomInfo;
};  

