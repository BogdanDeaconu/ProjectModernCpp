#pragma once
#include "Question.h"

class QuestionWithInteger : public Question
{
public:
	QuestionWithInteger(std::string question, int answer);
	~QuestionWithInteger();

	const int getAnswer() const;

	bool CheckAnswer(int answer, const QuestionWithInteger& question);

	friend std::ostream& operator<<(std::ostream& os, const QuestionWithInteger& question);
private:
	int m_answer;
};

