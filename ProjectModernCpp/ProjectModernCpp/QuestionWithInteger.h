#pragma once
#include "Question.h"

class QuestionWithInteger : public Question
{
public:
	QuestionWithInteger(std::string question, int answer);
	~QuestionWithInteger();

	const int getAnswer() const;

	template <typename T>
    T CheckAnswer(int answer);
	
	friend std::ostream& operator<<(std::ostream& os, const QuestionWithInteger& question);
private:
	int m_answer;
};

template <typename T>
T QuestionWithInteger::CheckAnswer(int answer)
{
	if (m_answer - answer == 0)
	{
		return true;
	}
	else
		return abs(m_answer - answer);
}

