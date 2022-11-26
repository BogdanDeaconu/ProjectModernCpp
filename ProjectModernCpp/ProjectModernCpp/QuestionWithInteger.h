#pragma once
#include <string>
#include <iostream>

class QuestionWithInteger 
{
public:
	QuestionWithInteger(std::string question, int answer);
	~QuestionWithInteger();

	const int getAnswer() const;

    int CheckAnswer(int answer);
	
	std::string GetQuestion();
	
	friend std::ostream& operator<<(std::ostream& os, QuestionWithInteger& question);
private:
	int m_answer;
	std::string m_question;
};


