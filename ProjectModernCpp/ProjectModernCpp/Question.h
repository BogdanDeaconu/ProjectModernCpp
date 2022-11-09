#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Question
{
public:
	Question(std::string question, std::string answer);
	~Question();

	std::string getQuestion() const;
	std::string getAnswers() const;
private:
	std::string m_question;
	std::unordered_map<std::string, bool>m_answers;
};

