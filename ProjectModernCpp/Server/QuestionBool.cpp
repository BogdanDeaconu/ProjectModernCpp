#include "QuestionBool.h"

QuestionBool::QuestionBool()
	:m_id(-1), m_question(""),m_rightanswer(""), m_wronganswer1(""), m_wronganswer2(""), m_wronganswer3("")
{ }

QuestionBool::QuestionBool(int id, std::string question, std::string rightanswer, std::string wronganswer1, std::string wronganswer2, std::string wronganswer3)
	:m_id(id), m_question(question), m_rightanswer(rightanswer), m_wronganswer1(wronganswer1), m_wronganswer2(wronganswer2), m_wronganswer3(wronganswer3)
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

void QuestionBool::SetRightAnswer(std::string right_answer)
{
	this->m_rightanswer = right_answer;
}

std::string QuestionBool::RightGetAnswer() const
{
	return this->m_rightanswer;
}

void QuestionBool::SetWrongAnswer1(std::string wrong_answer1)
{
	this->m_wronganswer1 = wrong_answer1;
}

std::string QuestionBool::WrongGetAnswer1() const
{
	return this->m_wronganswer1;
}

void QuestionBool::SetWrongAnswer2(std::string wrong_answer2)
{
	this->m_wronganswer2 = wrong_answer2;
}

std::string QuestionBool::WrongGetAnswer2() const
{
	return this->m_wronganswer2;
}

void QuestionBool::SetWrongAnswer3(std::string wrong_answer3)
{
	this->m_wronganswer3 = wrong_answer3;
}

std::string QuestionBool::WrongGetAnswer3() const
{
	return this->m_wronganswer3;
}








