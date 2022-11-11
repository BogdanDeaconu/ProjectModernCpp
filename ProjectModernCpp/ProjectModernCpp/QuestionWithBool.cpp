#include "QuestionWithBool.h"

QuestionWithBool::QuestionWithBool(std::string question, std::unordered_map<std::string, bool> answers)
	:Question(question),
	 m_answers(answers)
{  }

QuestionWithBool::~QuestionWithBool()
{  }

const std::unordered_map<std::string, bool> QuestionWithBool::getAnswers() const
{
	return m_answers;
}


bool QuestionWithBool::CheckAnswer(std::string answer, const QuestionWithBool & question)
{
	for (auto index : question.getAnswers())
	{
		if (index.first == answer)
		{
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const QuestionWithBool& question)
{
	os << question.getQuestion() << std::endl;
	for (auto answer : question.getAnswers())
	{
		os << answer.first << " ";
	}
	os << std::endl;
	return os;
}


