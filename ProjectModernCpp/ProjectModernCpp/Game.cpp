#include "Game.h"

Game::Game()
{
	ReadIntQ(m_questionswithinteger);
	ReadBoolQ(m_questionswithboool);
}

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
		in >> question;
		in >> answer; 
		Intquestions.push_back( new QuestionWithInteger(question, answer));
	}
}

void Game::ReadBoolQ(std::vector<QuestionWithBool*>& Boolquestions)
{
	std::string question;
	std::string answer;
	std::unordered_map<std::string, bool>umap;
	int correctAnswer;
	for (std::ifstream in("QuestionsBool.txt"); !in.eof(); /*EMPTY*/) {
		in >> question;
		for (int i = 0; i < 4; i++) {
			in >> answer >> correctAnswer;
			if (correctAnswer == 0) {
				umap[answer] = true;
			}
			else {
				umap[answer] = false;
			}
		}
		Boolquestions.push_back(new QuestionWithBool(question, umap));
	}
}
