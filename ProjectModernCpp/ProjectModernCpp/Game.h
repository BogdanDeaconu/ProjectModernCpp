#pragma once
#include "QuestionWithBool.h"
#include "QuestionWithInteger.h"
#include <array>
#include <time.h>

class Game
{
public:
	QuestionWithBool GetBoolQuestion();
	QuestionWithInteger GetIntegerQuestion();
	
private:
	static const std::size_t numberOfBoolQ = 70;
	static const std::size_t number0fIntQ = 30;
private:
	std::array<QuestionWithBool,numberOfBoolQ >m_questionswithboool;
	std::array<QuestionWithInteger,number0fIntQ >m_questionswithinteger;
};


