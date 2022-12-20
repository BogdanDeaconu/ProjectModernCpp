#include "Game.h"

Game::Game(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Game::~Game()
{}

void Game::on_GetBool_clicked()
{
    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/getquestionbool" });
    auto load = crow::json::load(r.text);
    ui.QuestionBool->setText(QString::fromStdString(load["question"].s()));
    ui.RightAnswer->setText(QString::fromStdString(load["1"].s()));
    ui.SecondAnswer->setText(QString::fromStdString(load["2"].s()));
    ui.ThirdAnswer->setText(QString::fromStdString(load["3"].s()));
    ui.FourthAnswer->setText(QString::fromStdString(load["4"].s()));
}