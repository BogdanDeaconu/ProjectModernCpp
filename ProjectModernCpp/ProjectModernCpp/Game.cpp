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

void Game::SelectBaseCoordinates(Board::Position pos, const Player& player)
{
	Territory territory;
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
		player1.WinDuel();
		player2.LoseDuel();
	}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer2) == 0) {
		player1.LoseDuel();
		player2.WinDuel();
	}
	if (question->CheckAnswer(answer1) == 0 and question->CheckAnswer(answer1) == 0) {
			//functie comparare timp cu time.h
	}
	if (question->CheckAnswer(answer1) != 0 and question->CheckAnswer(answer1) != 0) {
		if (question->CheckAnswer(answer1) > question->CheckAnswer(answer2)) {
			player1.WinDuel();
			player2.LoseDuel();
		}
		else {
			player1.LoseDuel();
			player2.WinDuel();
		}
	}
}

void Game::DeterminePlayersTurnOrder(std::vector<Player>& Players)
{
	QuestionWithInteger question("În ce an s-a născut Regele Mihai I?",1921);
	std::vector<int>answers;
	int answer;
	for (int i = 0; i < Players.size(); i++)
	{
		std::cin >> answer;
		answers.push_back(answer);
	}
	for (int i = 0; i < Players.size()-1; i++)
	{
		for (int j = 0; j < Players.size(); j++)
		{
			if (question.CheckAnswer(answers[i])>question.CheckAnswer(answers[j]))
			{
				std::swap(answers[i], answers[j]);
				//std::swap(Players[i], Players[j]);
			}
		}
	}
}

void Game::DistributeTerritory(Board::Position pos, const Player& player)
{
	Territory territory;
	territory.ConquerTerritory(player.GetColor());
	territory.SetTerritoryScore(100);
	board[pos] = territory;
}

void Game::StartGame(int PlayersNumber)
{
	Game game;
	board.ChooseNumberOfPlayers(PlayersNumber);
	board.SetBoardDimensions();
	uint8_t rounds;
	std::vector<Player>players;
	if (PlayersNumber==2)
	{
		rounds = 5;
		Player player1;
		player1.SetName("Player1");
		player1.SetColor(Player::Color::Blue);
		player1.SetScore(0);
		player1.SetStatus(Player::Status::Activ);
		Player player2;
		player2.SetName("Player2");
		player2.SetColor(Player::Color::Green);
		player2.SetScore(0);
		player2.SetStatus(Player::Status::Activ);
		players.push_back(player1);
		players.push_back(player2);
	}
	else
	{
		if (PlayersNumber==3)
		{
			rounds = 4;
			Player player1;
			player1.SetName("Player1");
			player1.SetColor(Player::Color::Blue);
			player1.SetScore(0);
			player1.SetStatus(Player::Status::Activ);
			Player player2;
			player2.SetName("Player2");
			player2.SetColor(Player::Color::Green);
			player2.SetScore(0);
			player2.SetStatus(Player::Status::Activ);
			Player player3;
			player3.SetName("Player3");
			player3.SetColor(Player::Color::Red);
			player3.SetScore(0);
			player3.SetStatus(Player::Status::Activ);
			players.push_back(player1);
			players.push_back(player2);
			players.push_back(player3);
		}
		else
		{
			rounds = 4;
			Player player1;
			player1.SetName("Player1");
			player1.SetColor(Player::Color::Blue);
			player1.SetScore(0);
			player1.SetStatus(Player::Status::Activ);
			Player player2;
			player2.SetName("Player2");
			player2.SetColor(Player::Color::Green);
			player2.SetScore(0);
			player2.SetStatus(Player::Status::Activ);
			Player player3;
			player3.SetName("Player3");
			player3.SetColor(Player::Color::Red);
			player3.SetScore(0);
			player3.SetStatus(Player::Status::Activ);
			Player player4;
			player4.SetName("Player4");
			player4.SetColor(Player::Color::Yellow);
			player4.SetScore(0);
			player4.SetStatus(Player::Status::Activ);
			players.push_back(player1);
			players.push_back(player2);
			players.push_back(player3);
			players.push_back(player4);
		}
	}
	DeterminePlayersTurnOrder(players);
	Board::Position pos;
	uint8_t line, column;
	for (int i = 0; i < players.size(); i++)
	{
		std::cin >> line >> column;
		pos = {line,column};
		game.SelectBaseCoordinates(pos, players[i]);
	}
	uint8_t NumberOfPlayers = board.GetNumberOfPlayers();
	for (int i = 0; i < players.size(); i++)
	{
		uint8_t TerrrytoryCount = NumberOfPlayers - (i+1);
		while (TerrrytoryCount)
		{
			std::cin >> line >> column;
			pos = { line,column };
			game.DistributeTerritory(pos, players[i]);
			TerrrytoryCount--;
		}
	}
}
