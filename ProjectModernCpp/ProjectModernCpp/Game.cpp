#include "Game.h"
#include <boost/regex/v4/iterator_category.hpp>
#include <boost/regex/v5/iterator_category.hpp>

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

void Game::SelectBaseCoordinates(Board::Position pos, Territory& territory, const Player& player)
{
	territory.ConquerTerritory(player.GetColor());
	territory.SetTerritoryScore(300);
	board[pos] = territory;
}

void Game::Duel(Player& player1, Player& player2)
{
	QuestionWithInteger* question = GetIntegerQuestion();
	std::cout << question->GetQuestion();
	std::cout << "\n";
	int answer1 = player1.PlayerAnswer();
	int answer2 = player2.PlayerAnswer();
	if (question->CheckAnswer(answer1) == 0 and question->CheckAnswer(answer2) = 0) {
		//player1 +100
		//player2 -100
	}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer2) == 0) {
			//player1 -100
			//player2 +100
	}
	if (question->CheckAnswer(answer1) == 0 and question->CheckAnswer(answer1) == 0) {
			//functie comparare timp cu time.h
	}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer1) != 0) {
		if (question->CheckAnswer(answer1) > question->CheckAnswer(answer2)) {
				//player1 +100
				//player2 -100
		}
		else {
				//player1 -100
				//player2 +100
		}
	}
}
