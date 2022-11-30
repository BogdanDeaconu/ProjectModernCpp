#pragma once
#include <iostream>
#include <string>
#include <vector>


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
	
	void SetWins(int wins);
	int GetWins()const;
	
	void SetLosses(int losses);
	int GetLosses()const;
	
private:
	int m_id;
	std::string m_userName;
	std::string m_password;
	int m_wins;
	int m_losses;
};

