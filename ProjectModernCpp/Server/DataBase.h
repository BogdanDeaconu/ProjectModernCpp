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
				sql::make_column("WinLoss", &Account::GetWinLoss, &Account::SetWinLoss)),
			sql::make_table("QuestionInt",
				sql::make_column("QI_ID", &QuestionInt::GetID, &QuestionInt::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("Question", &QuestionInt::GetQuestion, &QuestionInt::SetQuestion),
				sql::make_column("Answer", &QuestionInt::GetAnswer, &QuestionInt::SetAnswer)),
			sql::make_table("QuestionBool",
				sql::make_column("QB_ID", &QuestionBool::GetID, &QuestionBool::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("Question", &QuestionBool::GetQuestion, &QuestionBool::SetQuestion),
				sql::make_column("Answer", &QuestionBool::GetAnswer, &QuestionBool::SetAnswer)
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
	void AddQuestions();
};
