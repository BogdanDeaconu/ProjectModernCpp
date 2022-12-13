#include <iostream>
#include <string>

class Territory
{
public:
	Territory();
	
	~Territory();
	
	Territory(const Territory& x);
	
	Territory(int id,std::string name, int score);

	void SetID(int id);
	int GetID()const;

	void SetName(std::string name);
	std::string GetName();

	void SetScore(int score);
	int GetScore()const;

	void SetOwnerID(int id);
	int GetOwnerID()const;
	
private:
	int m_territoryid;
	std::string m_name;
	int m_score;
	int m_ownerid;
	
};

