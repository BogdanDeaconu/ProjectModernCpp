#pragma once
#include <iostream>
#include <string>
#include <vector>


enum class W_L : uint8_t {
	Win,
	Lost
};

class Account
{
public:
	Account();
	~Account();
	Account(const Account& x);
	Account(std::string username, std::string password);
	
	void SetID(int id);
	int GetID()const;
	
	void SetUserName(std::string userName);
	std::string GetUsername()const;
	
	void SetPassword(std::string password);
	std::string GetPassword()const;
	
	void SetWinLoss(W_L winLoss);
	std::vector<W_L> GetWinLoss()const;
	
private:
	int m_id;
	std::string m_userName;
	std::string m_password;
	std::vector<W_L> m_winsAndLosses;
};

