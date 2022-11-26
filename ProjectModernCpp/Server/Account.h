#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

enum class W_L : uint8_t {
		Win,
		Lost
	};
struct Account {
	int id;
	std::string username;
	std::string password;
	std::vector<std::pair<W_L, int>> history;
};

inline auto createAccount(const std::string& filename) {
	return sql::make_storage(
		filename,
		sql::make_table("accounts",
			sql::make_column("id", &Account::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("username", &Account::username),
			sql::make_column("password", &Account::password),
			sql::make_column("history", &Account::history)
		)
	);
}

using Accounts = decltype(createAccount(""));

void initAccounts(Accounts& db);

void addAccount(Accounts& db, const Account account);


