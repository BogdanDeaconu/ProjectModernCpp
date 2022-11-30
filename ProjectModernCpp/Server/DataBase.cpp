#include "DataBase.h"

void DataBase::initializeAccount(Account a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeQuestionInt(QuestionInt a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::initializeQuestionBool(QuestionBool a)
{
	m_db.sync_schema();
	m_db.insert(a);
	m_db.sync_schema();
}

void DataBase::AddQuestionsInt()
{
	std::ifstream InFile;
	std::vector<QuestionInt> QuestionsInt;
	int verifier = 0;
	std::string Line;
	InFile.open("C://Users//Bogdan//Documents//QuestionsInt.csv");
	std::getline(InFile, Line);
	while (std::getline(InFile, Line))
	{
		QuestionInt questionToRead;
		std::stringstream ss(Line);
		std::string substr, substr2;
		std::getline(ss, substr, ',');
		questionToRead.SetID(std::stoi(substr));
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetQuestion(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetAnswer(std::stoi(substr));
		substr = "";
		initializeQuestionInt(questionToRead);
	}
}

void DataBase::AddQuestionsBool()
{
	std::ifstream InFile;
	std::vector<QuestionBool> QuestionsBool;
	int verifier = 0;
	std::string Line;
	InFile.open("C://Users//Bogdan//Documents//QuestionsBool.csv");
	std::getline(InFile, Line);
	while (std::getline(InFile, Line))
	{
		QuestionBool questionToRead;
		std::stringstream ss(Line);
		std::string substr, substr2;
		std::getline(ss, substr, ',');
		questionToRead.SetID(std::stoi(substr));
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetQuestion(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetRightAnswer(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetWrongAnswer1(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetWrongAnswer2(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetWrongAnswer3(substr);
		substr = "";
		initializeQuestionBool(questionToRead);
	}
}