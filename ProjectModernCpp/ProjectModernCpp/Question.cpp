#include "Question.h"

Question::Question(std::string question, std::string answer)
{
}

Question::~Question()
{
}

std::string Question::getQuestion() const
{
	return m_question;
}

std::string Question::getAnswers() const
{
	return m_answers;
}