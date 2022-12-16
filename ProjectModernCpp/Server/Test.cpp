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
		CROW_ROUTE(app, "/getquestionbool")([&db]() {

			crow::json::wvalue question_bool;
			
			for (auto& question : db.m_db.iterate<QuestionBool>()) {
				//if pentru cautarea intrebarii in functie de id;
					question_bool["question"] = question.GetQuestion();
					question_bool["1"] = question.RightGetAnswer();
					question_bool["2"] = question.WrongGetAnswer1();
					question_bool["3"] = question.WrongGetAnswer2();
					question_bool["4"] = question.WrongGetAnswer3();
				return question_bool;
			}
		
		});
						
		app.port(18080).multithreaded().run();


		return 0;
		
}
