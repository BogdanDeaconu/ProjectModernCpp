#include "Game.h"

QuestionWithBool Game::GetBoolQuestion()
{
	return m_questionswithboool[rand() % numberOfBoolQ];
}

QuestionWithInteger Game::GetIntegerQuestion()
{
	return m_questionswithinteger[rand() % number0fIntQ];
}
