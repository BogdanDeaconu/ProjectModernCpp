#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class Question
{
public:
	Question(std::string question, std::unordered_map<std::string, bool> answers);
	~Question();

	const std::string getQuestion() const;
	const std::unordered_map<std::string,bool> getAnswers() const;
	
	bool CheckAnswer(std::string answer,const Question& question);

	friend std::ostream& operator<<(std::ostream& os, const Question& question);
	
	
private:
	std::string m_question;
	std::unordered_map<std::string, bool>m_answers;
};

