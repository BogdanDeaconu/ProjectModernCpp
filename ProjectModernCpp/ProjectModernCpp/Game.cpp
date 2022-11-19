#include "Game.h"

QuestionWithBool* Game::GetBoolQuestion()
{
	return m_questionswithboool[rand() % m_questionswithboool.size()];
}

QuestionWithInteger* Game::GetIntegerQuestion()
{
	return m_questionswithinteger[rand() % m_questionswithinteger.size()];
}

void Game::ReadIntQ(std::vector<QuestionWithInteger *>& Intquestions)
{
	std::string question;
	int answer;
	for (std::ifstream in("QuestionInteger.txt"); !in.eof(); /*EMPTY*/) {
		in >> question >> answer;
		Intquestions.push_back( new QuestionWithInteger(question, answer));
	}
}
