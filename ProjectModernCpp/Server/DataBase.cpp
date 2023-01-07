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
	int id = 1;
	while (id<=9)
	{
		QuestionInt questionToRead;
		std::stringstream ss(Line);
		std::string substr, substr2;
		questionToRead.SetID(id);
		id++;
		std::getline(ss, substr, ',');
		questionToRead.SetQuestion(substr);
		substr = "";
		std::getline(ss, substr, ',');
		questionToRead.SetAnswer(std::stoi(substr));
		substr = "";
		initializeQuestionInt(questionToRead);
		std::getline(InFile, Line);
	}
}

void DataBase::AddQuestionsBool()
{
	std::ifstream InFile2;
	std::vector<QuestionBool> QuestionsBool;
	int verifier = 0;
	std::string Line;
	InFile2.open("C://Users//Bogdan//Documents//QuestionsBool.csv");
	std::getline(InFile2, Line);
	int id = 1;
	while (id<=27)
	{
		QuestionBool questionToRead;
		std::stringstream ss(Line);
		std::string substr, substr2;
		questionToRead.SetID(id);
		id++;
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
		std::getline(InFile2, Line);
	}
}

std::vector<QuestionBool>DataBase::GetQuestionsBool(int numberOfQuestions)
{
    sqlite3* db;
    int rc = sqlite3_open("database.sqlite", &db);
    
    std::string sql = "SELECT question, rightanswer,wronganswer1,wronganswer2,wronganswer3 FROM questionbool LIMIT numberOfQuestions";

    
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    std::vector<QuestionBool> questions;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        QuestionBool q(sqlite3_column_int(stmt, 0), (char*)sqlite3_column_text(stmt, 1), (char*)sqlite3_column_text(stmt, 2), (char*)sqlite3_column_text(stmt, 3), (char*)sqlite3_column_text(stmt, 4), (char*)sqlite3_column_text(stmt, 5));
        questions.push_back(q);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return questions;
}

std::vector<QuestionInt> DataBase::GetQuestionsInt(int numberOfQuestions)
{
    sqlite3* db;
    int rc = sqlite3_open("database.sqlite", &db);

    std::string sql = "SELECT question, answer FROM questionint LIMIT numberOfQuestions";


    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    std::vector<QuestionInt> questions;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        QuestionInt q(sqlite3_column_int(stmt, 0), (char*)sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2));
        questions.push_back(q);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return questions;
}
