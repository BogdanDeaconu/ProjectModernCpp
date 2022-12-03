#include "DataBase.h"

int main(){

		DataBase db;
		db.AddQuestionsBool();
		db.AddQuestionsInt();
		return 0;

		crow::SimpleApp app;
		
		CROW_ROUTE(app, "/signupaccount")
			.methods("PUT"_method)
			([](const crow::request& req) {
			auto x = crow::json::load(req.body);
			if (!x)
				return crow::response(400);
			std::string username = x["username"].s();
			std::string password = x["password"].s();
			DataBase bazaDeDate;
			Account user(username, password);
			if (bazaDeDate.m_db.get_all<Account>(sql::where(sql::like(&Account::GetUsername, username))).size() == 0)
			{
				bazaDeDate.initializeAccount(user);
				return crow::response(200);
			}
			else
			{
				return crow::response(400);
			}
			});	
}
