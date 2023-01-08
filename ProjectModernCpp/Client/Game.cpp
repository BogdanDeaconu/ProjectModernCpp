#include "Game.h"

Game::Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Game::~Game()
{}

void Game::on_GetQuestionInt_clicked()
{
    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/getquestionint" });
    auto load = crow::json::load(r.text);
    QString question = QString::fromStdString(load["question"].s());
    ui.QuestionInt->setText(question);
    int answer = load["answer"].i();
    ui.IntAnswer->setText(QString::number(answer));
}