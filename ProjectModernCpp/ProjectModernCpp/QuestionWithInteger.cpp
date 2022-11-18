#include "QuestionWithInteger.h"

QuestionWithInteger::QuestionWithInteger(std::string question, int answer)
	:Question(question),
	 m_answer(answer)
{  }

QuestionWithInteger::~QuestionWithInteger()
{  }

const int QuestionWithInteger::getAnswer() const
{
	return m_answer;
}

bool QuestionWithInteger::CheckAnswer(int answer)
{
	if (answer == m_answer)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const QuestionWithInteger& question)
{
	os << question.getQuestion() << std::endl;
	return os;
}
