#include "QuestionWithBool.h"

QuestionWithBool::QuestionWithBool(std::string question, std::unordered_map<std::string, bool> answers)
	:m_question(question), m_answers(answers)
{  }

QuestionWithBool::~QuestionWithBool()
{  }

QuestionWithBool::QuestionWithBool()
{
}

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
	for (auto& pair : this->m_answers)
	{
		if (pair.first == answer)
		{
			return pair.second;
		}
	}
}

std::ostream& operator << (std::ostream & os, const QuestionWithBool & question)
{
		os << question.m_question << std::endl;
		for (auto& pair : question.m_answers)
		{
			os << pair.first << " " << pair.second << std::endl;
		}
		return os;
}



