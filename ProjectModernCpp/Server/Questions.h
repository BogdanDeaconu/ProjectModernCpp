#pragma once
#include <string>
#include <vector>
#include <crow.h>
#include <unordered_map>
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;



struct QuestionsWithInteger
{
	int id;
	std::string question_integer;
	int answer;
};


inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"QuestionsWithInteger",
			sql::make_column("id", &QuestionsWithInteger::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("name", &QuestionsWithInteger::question_integer),
			sql::make_column("price", &QuestionsWithInteger::answer)
		),
		sql::make_table(
			"QuestionsWithBool",
			sql::make_column("id", &QuestionsWithBool::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("idProduct", &QuestionsWithBool::question_bool),
			sql::make_column("quantity", &QuestionsWithBool::answers)
		)
	);
}

using Storage = decltype(createStorage(""));

void populateStorage(Storage& storage);