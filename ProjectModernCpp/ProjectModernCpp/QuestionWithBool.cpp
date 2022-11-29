#include "QuestionWithBool.h"

QuestionWithBool::QuestionWithBool(std::string question, std::unordered_map<std::string, bool> answers)
	:m_question(question), m_answers(answers)
{  }

QuestionWithBool::~QuestionWithBool()
{  }

const std::unordered_map<std::string, bool> QuestionWithBool::GetAnswers() const
{
	return m_answers;
}

std::string QuestionWithBool::GetQuestion() const
{
	return m_question;
}



bool QuestionWithBool::CheckAnswer(std::string answer)
{
	for (auto& pair : m_answers)
	{
		if (pair.first == answer)
		{
			return pair.second;
		}
}


std::ostream& operator<<(std::ostream& os, const QuestionWithBool& question)
{
	os << question.m_question << std::endl;
	for (auto& answer : question.GetAnswers())
	{
		os << answer.first << " ";
	}
	os << std::endl;
	return os;
}



