#include "QuestionInt.h"

QuestionInt::QuestionInt()
	:m_id(-1),m_question(""),m_answer()
{ }

QuestionInt::QuestionInt(int id,std::string question, int answer)
	:m_id(id), m_question(question), m_answer(answer)
{ }
QuestionInt::~QuestionInt()
{ }

void QuestionInt::SetID(int id)
{
	this->m_id = id;
}

int QuestionInt::GetID()const
{
	return this->m_id;
}

void QuestionInt::SetQuestion(std::string question)
{
	this->m_question = question;
}

std::string QuestionInt::GetQuestion()const
{
	return this->m_question;
}

void QuestionInt::SetAnswer(int answer)
{
	this->m_answer = answer;
}

int QuestionInt::GetAnswer()const
{
	return this->m_answer;
}
