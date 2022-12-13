#include "DataBase.h"
#include "utils.h"

int main(){

		DataBase db;
		db.AddQuestionsBool();
		db.AddQuestionsInt();

		crow::SimpleApp app;
		
		CROW_ROUTE(app, "/signupaccount")
			.methods("PUT"_method)
			([&db](const crow::request& req) {
			auto x = parseUrlArgs(req.body);
			auto username = x["username"];
			auto password = x["password"];
			Account account(username,password);
			for (auto& user : db.m_db.iterate<Account>()) {
				if (user.GetUsername() == username) {
					return crow::response(400);
				}
				else {
					db.initializeAccount(account);
					return crow::response(200);
				}
			}
			});
			
		CROW_ROUTE(app, "/loginaccount")
			.methods("POST"_method)
			([&db](const crow::request& req) {
			auto x = parseUrlArgs(req.body);
			auto username = x["username"];
			auto password = x["password"];
			for (auto& user : db.m_db.iterate<Account>())
			{
				if (user.GetUsername() == username)
				{
					if (user.GetPassword() == password)
					{
						return crow::response(200);
					}
					else
					{
						return crow::response(401, "Wrong password");
					}
				}
				else {
					return crow::response(401, "Account not found");
				}
			}
			});

		app.port(18080).multithreaded().run();

		return 0;
		
}
