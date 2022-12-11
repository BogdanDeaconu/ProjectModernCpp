#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class QuestionWithBool 
{
public:
	QuestionWithBool(std::string question, std::unordered_map<std::string, bool> answers);
	~QuestionWithBool();
	QuestionWithBool();
	const std::unordered_map<std::string, bool> GetAnswers() const;
	std::string GetQuestion() const;
	
	bool CheckAnswer(std::string answer);
	
	friend std::ostream& operator << (std::ostream& os, const QuestionWithBool& question);
private:
	std::string m_question;
	const std::unordered_map<std::string, bool> m_answers;
};

