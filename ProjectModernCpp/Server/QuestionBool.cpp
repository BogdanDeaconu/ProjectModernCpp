#include "QuestionBool.h"

QuestionBool::QuestionBool()
	:m_id(-1),m_question(""),m_answer()
{ }

QuestionBool::QuestionBool(int id,std::string question, std::unordered_map<std::string, bool> answers)
	:m_id(id),m_question(question),m_answer(answers)
{ }

QuestionBool::~QuestionBool()
{ }

void QuestionBool::SetID(int id)
{
	this->m_id = id;
}

int QuestionBool::GetID() const
{
	return this->m_id;
}

void QuestionBool::SetQuestion(std::string question)
{
	this->m_question = question;
}

std::string QuestionBool::GetQuestion() const
{
	return this->m_question;
}

void QuestionBool::SetAnswer(std::unordered_map<std::string, bool> answer)
{
	this->m_answer = answer;
}

std::unordered_map<std::string, bool> QuestionBool::GetAnswer() const
{
	return this->m_answer;
}






