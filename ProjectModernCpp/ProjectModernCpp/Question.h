#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Question
{
public:
	Question(std::string question);
	~Question();

	const std::string getQuestion() const;
private:
	std::string m_question;
	
};

