#include "DataBase.h"

int main(){

		DataBase db;
		//db.AddQuestionsBool();
		//db.AddQuestionsInt();

		crow::SimpleApp app;
		
		CROW_ROUTE(app, "/signupaccount/<string>/<string>")
			.methods("PUT"_method)
			([&db](const crow::request& req) {
			auto x = crow::json::load(req.body);
			if (!x) {
				return crow::response(400);
			}
			std::string username = x["username"].s();
			std::string password = x["password"].s();
			Account user(username,password);
			if (db.m_db.get_all<Account>(sql::where(sql::like(&Account::GetUsername, username))).size() == 0)
			{
				db.initializeAccount(user);
				return crow::response(200);
			}
			else
			{
				return crow::response(401);
			}
			});
			
		CROW_ROUTE(app, "/loginaccount")
			.methods("PUT"_method)
			([&db](const crow::request& req) {
			auto x = crow::json::load(req.body);
			if (!x) {
				return crow::response(400);
			}
			std::string username = x["username"].s();
			std::string password = x["password"].s();
			Account user(username, password);
			if (db.m_db.get_all<Account>(sql::where(sql::like(&Account::GetUsername, username))).size() == 0)
			{
				return crow::response(401);
			}
			else
			{
				return crow::response(200);
			}
			});

		app.port(18080).multithreaded().run();


		return 0;
		
}
