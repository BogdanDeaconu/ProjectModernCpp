#include "Account.h"

Account::Account()
	:m_id(-1), m_userName(""), m_password(""), m_wins(),m_losses()
{ }

Account::~Account()
{ }

Account::Account(const Account& x)
	:m_id(x.m_id),m_password(x.m_password),
	m_userName(x.m_userName), m_wins(x.m_wins), m_losses(x.m_losses)
{ }

Account::Account(std::string username, std::string password)
	:m_id(-1), m_userName(username), m_password(password), m_wins() , m_losses()
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

void Account::SetWins(int wins)
{
	this->m_wins = wins;
}

int Account::GetWins()const
{
	return this->m_wins;
}

void Account::SetLosses(int losses)
{
	this->m_losses = losses;
}

int Account::GetLosses()const
{
	return this->m_losses;
}