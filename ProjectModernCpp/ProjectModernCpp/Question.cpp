#include "Question.h"

Question::Question(std::string question) 
	: m_question(question)
{ }

Question::~Question()
{ }

const std::string Question::getQuestion() const
{
	return m_question;
}



