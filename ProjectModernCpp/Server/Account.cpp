#include "Account.h"

Account::Account()
	:m_id(-1), m_userName(""), m_password(""), m_winsAndLosses()
{ }

Account::~Account()
{ }

Account::Account(const Account& x)
	:m_id(x.m_id),m_password(x.m_password),
	 m_userName(x.m_userName),m_winsAndLosses(x.m_winsAndLosses)
{ }

Account::Account(std::string username, std::string password)
	:m_id(-1), m_userName(username), m_password(password), m_winsAndLosses()
{ }

void Account::SetID(int id)
{
	this->m_id = id;
}

int Account::GetID()const
{
	return this->m_id;
}

void Account::SetUserName(std::string userName)
{
	this->m_userName = userName;
}

std::string Account::GetUsername()const
{
	return this->m_userName;
}

void Account::SetPassword(std::string password)
{
	this->m_password = password;
}

std::string Account::GetPassword()const
{
	return this->m_password;
}

void Account::SetWinLoss(W_L winLoss)
{
	this->m_winsAndLosses.push_back(winLoss);
}

std::vector<W_L> Account::GetWinLoss()const
{
	return this->m_winsAndLosses;
}