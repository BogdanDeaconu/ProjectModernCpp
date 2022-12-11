#include "Game.h"
#include"QuestionWithInteger.h"
#include"Player.h"
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


void Game::Duel(int order1, int order2)
{
	QuestionWithInteger* question = GetIntegerQuestion();
	std::cout << question->GetQuestion();
	std::cout << "\n";
	int answer1 = m_players[order1].PlayerAnswer();
	int answer2 = m_players[order2].PlayerAnswer();
	//if (question->CheckAnswer(answer1) == 0 and question->CheckAnswer(answer2) = 0) {
	//	m_players[order1].WinDuel();
	//	m_players[order2].LoseDuel();
	//}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer2) == 0) {
		m_players[order1].LoseDuel();
		m_players[order2].WinDuel();
	}
	if (question->CheckAnswer(answer1) == 0 and question->CheckAnswer(answer1) == 0) {
			//functie comparare timp cu time.h
	}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer1) != 0) {
		if (question->CheckAnswer(answer1) > question->CheckAnswer(answer2)) {
			m_players[order1].WinDuel();
			m_players[order2].LoseDuel();
		}
		else {
			m_players[order1].LoseDuel();
			m_players[order2].WinDuel();
		}
	}
}

void Game::DeterminePlayersTurnOrder()
{
	QuestionWithInteger question("În ce an s-a născut Regele Mihai I?",1921);
	std::vector<int>answers;
	int answer;
	for (int i = 0; i < m_players.size(); i++)
	{
		std::cin >> answer;
		answers.push_back(answer);
	}
	for (int i = 0; i < m_players.size()-1; i++)
	{
		for (int j = 0; j < m_players.size(); j++)
		{
			if (question.CheckAnswer(answers[i])>question.CheckAnswer(answers[j]))
			{
				std::swap(answers[i], answers[j]);
				//std::swap(Players[i], Players[j]);
			}
		}
	}
}

void Game::ConquerTerritory(Board::Position pos, int order)
{
	
	 m_board[pos].SetTerritoryColor(m_players[order].GetColor());
	
}

void Game::DistributeTerritory(Board::Position pos,int order)
{
	ConquerTerritory(pos,order);
	m_board[pos].SetTerritoryScore(100);
}

uint8_t Game::ChooseAdvantage(const Player& player,std::array<uint8_t,3>& Advantage)
{
		Board::Position pos;
		uint8_t advantage;
		uint8_t unavailable_advantage = 4;
		int line, column;
		std::cin >> line >> column;
		std::cin >> advantage;
		pos = { line,column };
		if (m_board[pos].GetScore()>=200 and Advantage[advantage]!=0)
		{
			uint32_t new_score;
			new_score = m_board[pos].GetScore() - 100;
			Advantage[advantage] = 0;
			return advantage;
		}
		return unavailable_advantage;
}

std::unordered_map<std::string, bool> Game::FiftyFiftyAdvantage()
{
	uint8_t count = 2;
	std::string corect_answer;
	std::string answer2;
	std::string answer3;
	std::string answer4;
	std::cin >> corect_answer >> answer2 >> answer3 >> answer4;
	std::unordered_map<std::string, bool>question({ {corect_answer,0},{answer2,1},{answer3,1},{answer4,1} });
	question.erase(answer3);
	question.erase(answer4);
	return question;
}

void Game::StartGame(int PlayersNumber)
{
	Game game;
	m_board.ChooseNumberOfPlayers(PlayersNumber);
	m_board.SetBoardDimensions();
	uint8_t rounds;
	if (PlayersNumber==2)
	{
		rounds = 5;
		Player player1;
	    std:: array<uint8_t, 3>Player1Advantages;
		for (int i = 0; i < Player1Advantages.size(); i++)
		{
			Player1Advantages[i] = 1;
		}
		player1.SetName("Player1");
		player1.SetColor(Color::Blue);
		player1.SetScore(0);
		player1.SetStatus(Player::Status::Activ);
		Player player2;
		std::array<uint8_t, 3>Player2Advantages;
		for (int i = 0; i < Player2Advantages.size(); i++)
		{
			Player2Advantages[i] = 1;
		}
		player2.SetName("Player2");
		player2.SetColor(Color::Green);
		player2.SetScore(0);
		player2.SetStatus(Player::Status::Activ);
		m_players.push_back(player1);
		m_players.push_back(player2);
	}
	else
	{
		if (PlayersNumber==3)
		{
			rounds = 4;
			Player player1;
			std::array<uint8_t, 3>Player1Advantages;
			for (int i = 0; i < Player1Advantages.size(); i++)
			{
				Player1Advantages[i] = 1;
			}
			player1.SetName("Player1");
			player1.SetColor(Color::Blue);
			player1.SetScore(0);
			player1.SetStatus(Player::Status::Activ);
			Player player2;
			std::array<uint8_t, 3>Player2Advantages;
			for (int i = 0; i < Player2Advantages.size(); i++)
			{
				Player2Advantages[i] = 1;
			}
			player2.SetName("Player2");
			player2.SetColor(Color::Green);
			player2.SetScore(0);
			player2.SetStatus(Player::Status::Activ);
			Player player3;
			std::array<uint8_t, 3>Player3Advantages;
			for (int i = 0; i < Player3Advantages.size(); i++)
			{
				Player3Advantages[i] = 1;
			}
			player3.SetName("Player3");
			player3.SetColor(Color::Red);
			player3.SetScore(0);
			player3.SetStatus(Player::Status::Activ);
			m_players.push_back(player1);
			m_players.push_back(player2);
			m_players.push_back(player3);
		}
		else
		{
			rounds = 4;
			Player player1;		
			std::array<uint8_t, 3>Player1Advantages; 
			for (int i = 0; i < Player1Advantages.size(); i++)
			{
				Player1Advantages[i] = 1;
			}
			player1.SetName("Player1");
			player1.SetColor(Color::Blue);
			player1.SetScore(0);
			player1.SetStatus(Player::Status::Activ);
			Player player2;
			std::array<uint8_t, 3>Player2Advantages;
			for (int i = 0; i < Player2Advantages.size(); i++)
			{
				Player2Advantages[i] = 1;
			}
			player2.SetName("Player2");
			player2.SetColor(Color::Green);
			player2.SetScore(0);
			player2.SetStatus(Player::Status::Activ);
			Player player3;
			std::array<uint8_t, 3>Player3Advantages;
			for (int i = 0; i < Player3Advantages.size(); i++)
			{
				Player3Advantages[i] = 1;
			}
			player3.SetName("Player3");
			player3.SetColor(Color::Red);
			player3.SetScore(0);
			player3.SetStatus(Player::Status::Activ);
			Player player4;
			std::array<uint8_t, 3>Player4Advantages;
			for (int i = 0; i < Player4Advantages.size(); i++)
			{
				Player4Advantages[i] = 1;
			}
			player4.SetName("Player4");
			player4.SetColor(Color::Yellow);
			player4.SetScore(0);
			player4.SetStatus(Player::Status::Activ);
			m_players.push_back(player1);
			m_players.push_back(player2);
			m_players.push_back(player3);
			m_players.push_back(player4);
		}
	}
	DeterminePlayersTurnOrder();
	Board::Position pos;
	uint8_t line, column;
	for (int i = 0; i < m_players.size(); i++)
	{
		std::cin >> line >> column;
		pos = {line,column};
		game.DistributeTerritory(pos, i);
	}
	uint8_t NumberOfPlayers = m_board.GetNumberOfPlayers();
	for (int i = 0; i < m_players.size(); i++)
	{
		uint8_t TerrrytoryCount = NumberOfPlayers - (i+1);
		while (TerrrytoryCount)
		{
			std::cin >> line >> column;
			pos = { line,column };
			game.DistributeTerritory(pos, i);
			TerrrytoryCount--;
		}
	}
}
