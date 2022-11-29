#pragma once
#include <iostream>
#include <string.h>


class QuestionInt
{
public:
	QuestionInt();
	~QuestionInt();

	void SetID(int id);
	int GetID()const;

	void SetQuestion(std::string question);
	std::string GetQuestion()const;

	void SetAnswer(int answer);
	int GetAnswer()const;
private:
	int m_id;
	std::string m_question;
	int m_answer;
};

