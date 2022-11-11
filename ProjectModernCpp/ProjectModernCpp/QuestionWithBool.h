#pragma once
#include "Question.h"
#include <unordered_map>

class QuestionWithBool : public Question
{
public:
	QuestionWithBool(std::string question, std::unordered_map<std::string, bool> answers);
	~QuestionWithBool();

	const std::unordered_map<std::string, bool> getAnswers() const;
	
	bool CheckAnswer(std::string answer, const QuestionWithBool& question);
	
	friend std::ostream& operator<<(std::ostream& os, const QuestionWithBool & question);
private:
	const std::unordered_map<std::string, bool> m_answers;
};

