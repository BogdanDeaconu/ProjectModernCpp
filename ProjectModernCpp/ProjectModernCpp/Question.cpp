#include "Question.h"

Question::Question(std::string question, std::unordered_map<std::string, bool> answers) 
	: m_question(question), m_answers(answers)
{ }

Question::~Question()
{ }

const std::string Question::getQuestion() const
{
	return m_question;
}

const std::unordered_map<std::string, bool> Question::getAnswers() const
{
	return m_answers;
}

bool Question::CheckAnswer(std::string answer, const Question& question)
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

std::ostream& operator<<(std::ostream& os, const Question& question)
{
	os << question.getQuestion() << std::endl;
	for (auto answer : question.getAnswers())
	{
		os << answer.first << " "; 
	}
	os << std::endl;
	return os;
}


