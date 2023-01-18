#include "DataBase.h"
#include "utils.h"
#include "Lobby.h"

int main() {

    DataBase db;
    int numberofplayers = 0;
    db.AddQuestionsBool();
    db.AddQuestionsInt();
    GamesStorage dblobby = createStorageGame("games.sqllite");
    dblobby.sync_schema();
    int players;
    crow::SimpleApp app;

    CROW_ROUTE(app, "/signupaccount")
        .methods("PUT"_method)
        ([&db](const crow::request& req) {
        auto x = parseUrlArgs(req.body);
        auto username = x["username"];
        auto password = x["password"];
        Account account(username, password);

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
        return crow::json::wvalue{ x };
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

    CROW_ROUTE(app, "/createLobby").methods("PUT"_method)
        ([&dblobby](const crow::request& req){
        auto urlArgs = parseUrlArgs(req.body);
        auto username = urlArgs["username"];
        for (auto game : dblobby.iterate<Lobby>())
        {
            if (game.isStarted() == true && username == game.getOwner())
            {
                return crow::response(400);
            }
        }

        Lobby lobby(username, "", "", "", "", 1);
        dblobby.insert(lobby);
        return crow::response(200);
        });

    CROW_ROUTE(app, "/joinLobby").methods("POST"_method)
        ([&dblobby](const crow::request& req) {
        auto urlArgs = parseUrlArgs(req.body);
        auto username = urlArgs["username"];
        auto gameOwner = urlArgs["gameOwner"];
        for (auto game : dblobby.iterate<Lobby>())
        {
            if (game.getOwner() == gameOwner)
            {

                game.addPlayer(username);
                dblobby.update(game);
                return crow::response(200);
            }
        }
        return crow::response(400);
        });
		

       CROW_ROUTE(app, "/getsplayer")([&dblobby](const crow::request& req) {
            auto urlArgs = parseUrlArgs(req.body);
            auto username = urlArgs["username"];
            for (auto game : dblobby.iterate<Lobby>())
            {
                if (game.getOwner() == "gameOwner")
                {
                    std::string players = game.getPlayer1() + "," + game.getPlayer2() + "," + game.getPlayer3() + "," + game.getPlayer4();
                    return crow::response(200, players);
                }
            }
            return crow::response(401);
            });

        app.port(18080).multithreaded().run();
		return 0;
		
}
