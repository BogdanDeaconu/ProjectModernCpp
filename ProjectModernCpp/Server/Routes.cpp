#include "DataBase.h"
#include "utils.h"
#include "GameRoom.h"

int main(){

		DataBase db;
		int numberofplayers = 0;
		db.AddQuestionsBool();
		db.AddQuestionsInt();
        std::vector<Player>players;
        GameRoom room;
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
			}
			db.initializeAccount(account);
	        return crow::response(200);
			
			});

		CROW_ROUTE(app, "/loginaccount")
			.methods("POST"_method)
			([&db](const crow::request& req) {
			auto x = parseUrlArgs(req.body);
			auto username = x["username"];
			auto password = x["password"];
			Account account(username, password);
			for (auto& user : db.m_db.iterate<Account>()) {
				if (user.GetUsername() == username && user.GetPassword() == password) {
					return crow::response(201);
				}
				else {
					return crow::response(400);
				}
			}
			});

		CROW_ROUTE(app, "/playerstartgame")([&numberofplayers]() {
			numberofplayers = 1;
			auto x = crow::json::wvalue{ {"numberofplayers",numberofplayers} };
			return crow::json::wvalue{x};
		});
		
		CROW_ROUTE(app, "/playerjoingame")([&numberofplayers]() {
			if (numberofplayers > 0 and numberofplayers < 4) {
				numberofplayers++;
			}
			auto x = crow::json::wvalue{ {"numberofplayers",numberofplayers} };
			return crow::json::wvalue{ x };
		});

		CROW_ROUTE(app, "/getquestionbool")([&db]() {
            int random = rand() % 30;
			crow::json::wvalue question_bool;
			
			for (auto& question : db.m_db.iterate<QuestionBool>()) {
				
                if (question.GetID() == random) {
                    question_bool["question"] = question.GetQuestion();
                    question_bool["1"] = question.RightGetAnswer();
                    question_bool["2"] = question.WrongGetAnswer1();
                    question_bool["3"] = question.WrongGetAnswer2();
                    question_bool["4"] = question.WrongGetAnswer3();
                    return crow::json::wvalue{ question_bool };
                }
			}
		
		});
		CROW_ROUTE(app, "/qetquestionint")([&db]() {
            int random = rand() % db.m_db.count<QuestionInt>();
			crow::json::wvalue question_int;
		for(auto& question :db.m_db.iterate<QuestionInt>())
		{
            if (question.GetID() == random) {
                question_int["question"] = question.GetQuestion();
                question_int["answer"] = question.GetAnswer();

                return crow::json::wvalue{ question_int };
            }
		}
		});
     
        CROW_ROUTE(app, "/createRoom")([&room]() {
            crow::json::wvalue x;
                x["id"] = room.getRoomInfo().id;
                x["name"] = room.getRoomInfo().name;
                x["maxPlayers"] = room.getRoomInfo().maxPlayers;
                x["numberOfQuestions"] = room.getRoomInfo().numberOfQuestions;
                x["boardDimension"] = room.getRoomInfo().boardDimensions;
                x["timeForQuestion"] = room.getRoomInfo().timeForQuestion;
                x["isActive"] = room.getRoomInfo().isActive;

            return crow::json::wvalue{ x };

        });
        
		app.port(18080).multithreaded().run();


		return 0;
		
}
