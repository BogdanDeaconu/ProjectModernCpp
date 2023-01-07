#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Account.h"
#include "QuestionInt.h"
#include "QuestionBool.h"


#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

const std::string DB_FILE = "database.db";
inline auto createStorage(const std::string& filename) 
{
		return sql::make_storage(
			filename,
			sql::make_table("Account",
				sql::make_column("A_ID", &Account::GetID, &Account::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("UserName", &Account::GetUsername, &Account::SetUserName),
				sql::make_column("Password", &Account::GetPassword, &Account::SetPassword),
				sql::make_column("Wins", &Account::GetWins, &Account::SetWins),
				sql::make_column("Losses", &Account::GetLosses, &Account::SetLosses)),
			sql::make_table("QuestionInt",
				sql::make_column("QI_ID", &QuestionInt::GetID, &QuestionInt::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("Question", &QuestionInt::GetQuestion, &QuestionInt::SetQuestion),
				sql::make_column("Answer", &QuestionInt::GetAnswer, &QuestionInt::SetAnswer)),
			sql::make_table("QuestionBool",
				sql::make_column("QB_ID", &QuestionBool::GetID, &QuestionBool::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("Question", &QuestionBool::GetQuestion, &QuestionBool::SetQuestion),
				sql::make_column("RightAnswer", &QuestionBool::RightGetAnswer, &QuestionBool::SetRightAnswer),
				sql::make_column("WrongAnswer1", &QuestionBool::WrongGetAnswer1, &QuestionBool::SetWrongAnswer1),
				sql::make_column("WrongAnswer2", &QuestionBool::WrongGetAnswer2, &QuestionBool::SetWrongAnswer2),
				sql::make_column("WrongAnswer3", &QuestionBool::WrongGetAnswer3, &QuestionBool::SetWrongAnswer3)
		));
}

using Storage = decltype(createStorage(" "));

class DataBase
{
public:
	Storage m_db = createStorage(DB_FILE);
	void initializeAccount(Account a);
	void initializeQuestionInt(QuestionInt a);
	void initializeQuestionBool(QuestionBool a);
	void AddQuestionsInt();
	void AddQuestionsBool();
    std::vector<QuestionBool>GetQuestionsBool(int numberOfQuestions);
    //std::vector<QuestionBool>* GetQuestionsBool(int numberOfQuestions);
    
};
