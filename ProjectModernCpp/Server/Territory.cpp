#include "Territory.h"

Territory::Territory() 
	:m_territoryid(-1),m_name(""), m_score(0), m_ownerid(-1)
{ }

Territory::~Territory()
{ }

Territory::Territory(const Territory& x)
	:m_territoryid(x.m_territoryid),m_name(x.m_name), m_score(x.m_score), m_ownerid(x.m_ownerid)
{ }

Territory::Territory(int id,std::string name, int score)
	:m_territoryid(id),m_name(name), m_score(score), m_ownerid(-1)
{ }

void Territory::SetID(int id)
{
	this->m_territoryid = id;
}

int Territory::GetID()const
{
	return this->m_territoryid;
}

void Territory::SetName(std::string name) {
	this->m_name = name;
}

std::string Territory::GetName() {
	return this->m_name;
}

void Territory::SetScore(int score)
{
	this->m_score = score;
}

int Territory::GetScore()const
{
	return this->m_score;
}

void Territory::SetOwnerID(int id)
{
	this->m_ownerid = id;
}

int Territory::GetOwnerID()const
{
	return this->m_ownerid;
}


