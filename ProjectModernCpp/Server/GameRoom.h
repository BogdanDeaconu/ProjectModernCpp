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
    
    bool addPlayer(const Player& player);
    bool removePlayer(const Player& player);
    std::vector<Player> getPlayers() const;
    RoomInfo getRoomInfo() const;
    void setRoomInfo(RoomInfo roomInfo) { this->m_roomInfo = roomInfo; }
    void setGameHasBegun(bool gameHasBegun) { this->gameHasBegun = gameHasBegun; }
    bool getGameHasBegun() const { return this->gameHasBegun; }
    std::vector<std::string>getAllUsernames();
    
    
private:
    bool gameHasBegun;
    std::vector<Player> m_players;
    RoomInfo m_roomInfo;
};  

