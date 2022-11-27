#include "QuestionWithInteger.h"

QuestionWithInteger::QuestionWithInteger(std::string question, int answer)
	 :m_answer(answer),m_question(question)
{  }

QuestionWithInteger::~QuestionWithInteger()
{  }

QuestionWithInteger::QuestionWithInteger()
{
}

const int QuestionWithInteger::getAnswer() const
{
	return m_answer;
}

int QuestionWithInteger::CheckAnswer(int answer)
{	
     return abs(m_answer - answer);
}

std::string QuestionWithInteger::GetQuestion()
{
	return m_question;
}

std::ostream& operator<<(std::ostream& os, QuestionWithInteger& question)
{
	os << question.GetQuestion();
	return os;
}

