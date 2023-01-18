//#include "game.h"
//
//
//
//void game::addplayer(const player& player)
//{
//	m_players.push_back(player);
//}
//void game::setplayeradvantages(const player& player)
//{
//	std::array<uint8_t, 3>player_advantage;
//	for (int i = 0; i < player_advantage.size(); i++)
//	{
//		player_advantage[i] = 1;
//	}
//	m_playersadvantages.push_back(player_advantage);
//}
//uint8_t game::determinenumberofrounds(uint8_t n)
//{
//	uint8_t rounds;
//	if (n == 2)
//	{
//		rounds = 5;
//	}
//	else
//	{
//		if (n == 3)
//		{
//			rounds = 4;
//		}
//		else
//		{
//			rounds = 4;
//		}
//	}
//	return rounds;
//}
//
//void game::determineplayersturnorder()
//{
//	questionint question(1,"în ce an s-a născut regele mihai i?", 1921);
//	std::vector<int>answers;
//	int answer;
//	for (int i = 0; i < m_players.size(); i++)
//	{
//		std::cin >> answer;
//		answers.push_back(answer);
//	}
//	for (int i = 0; i < m_players.size() - 1; i++)
//	{
//		for (int j = 0; j < m_players.size(); j++)
//		{
//			if (question.checkanswer(answers[i]) > question.checkanswer(answers[j]))
//			{
//				std::swap(answers[i], answers[j]);
//				//std::swap(players[i], players[j]);
//				//swap function of two players
//			}
//		}
//	}
//}
//uint8_t game::chooseadvantage(const player& player, std::array<uint8_t, 3>& advantage)
//{
//    uint8_t advantage;
//    uint8_t unavailable_advantage = 4;
//    int line, column;
//    std::cin >> line >> column;
//    std::cin >> advantage;
//    //if (m_board[line][column].getscore() >= 200 and advantage[advantage] != 0)
//    //{
//        //uint32_t new_score;
//       // new_score = m_board[line][column].getscore() - 100;
//        //m_board[line][column].setscore(new_score);
//        //advantage[advantage] = 0;
//        //return advantage;
//    //}
//    return unavailable_advantage;
//}
//void game::conquerterritory(uint8_t line, uint8_t column, uint8_t order)
//{
//
//    //m_board[line][column].setterritorycolor(m_players[order].getcolor());
//
//}
//void game::distributeterritory(uint8_t line, uint8_t column, uint8_t order)
//{
//    conquerterritory(line,column, order);
//    //m_board[line][column].setterritoryscore(100);
//}
//std::unordered_map<std::string, bool> game::fiftyfiftyadvantage()
//{
//    uint8_t count = 2;
//    std::string corect_answer;
//    std::string answer2;
//    std::string answer3;
//    std::string answer4;
//    std::cin >> corect_answer >> answer2 >> answer3 >> answer4;
//    std::unordered_map<std::string, bool>question({ {corect_answer,0},{answer2,1},{answer3,1},{answer4,1} });
//    question.erase(answer3);
//    question.erase(answer4);
//    return question;
//}
//
//std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> game::chooseansweradvantage(questionint question)
//{
//    std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> answers;
//    uint16_t corectanswer = question.getanswer();
//    uint16_t answer2 = question.getanswer() - 10;
//    uint16_t answer3 = question.getanswer() + 10;
//    uint16_t answer4 = question.getanswer() - 18;
//    answers = std::make_tuple(corectanswer, answer2, answer3, answer4);
//    return answers;
//}
//
//uint16_t game::suggestansweradvantage(questionint question)
//{
//    uint16_t corectanswer = question.getanswer();
//    uint16_t closeanswer1 = question.getanswer() - 5;
//    uint16_t closeanswer2 = question.getanswer() + 5;
//    uint16_t closeanswer3 = question.getanswer() + 3;
//    uint8_t random= 1 + (rand() % 4);
//    if (random==1)
//    {
//        return corectanswer;
//    }
//    else
//    {
//        if (random==2)
//        {
//            return closeanswer1;
//        }
//        else
//        {
//            if (random==3)
//            {
//                return closeanswer2;
//            }
//            else
//            {
//                return closeanswer3;
//            }
//        }
//    }
//}
//
//
