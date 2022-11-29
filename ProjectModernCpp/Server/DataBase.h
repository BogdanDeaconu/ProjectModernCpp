#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Account.h"
#include "QuestionInt.h"

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

const std::string DB_NAME = "database.db";
inline auto createStorage(const std::string& filename) {
	{
		return sql::make_storage(
			filename,
			sql::make_table("Account",
				sql::make_column("ID", &Account::GetID, &Account::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("UserName", &Account::GetUsername, &Account::SetUserName),
				sql::make_column("Password", &Account::GetPassword, &Account::SetPassword),
				sql::make_column("WinLoss", &Account::GetWinLoss, &Account::SetWinLoss),
			sql::make_table("QuestionInt",
				sql::make_column("ID", &QuestionInt::GetID, &QuestionInt::SetID, sql::autoincrement(), sql::primary_key()),
				sql::make_column("Question", &QuestionInt::GetQuestion, &QuestionInt::SetQuestion),
				sql::make_column("Answer", &QuestionInt::GetAnswer, &QuestionInt::SetAnswer)
			
			)
		);
	}
}

