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

void Game::on_GetQuestionBool_clicked()
{
    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/getquestionbool" });
    auto load = crow::json::load(r.text);
    QString question = QString::fromStdString(load["question"].s());
    ui.QuestionBool->setText(question);
    QString answer1 = QString::fromStdString(load["answer1"].s());
    ui.RightAnswer->setText(answer1);
    QString answer2 = QString::fromStdString(load["answer2"].s());
    ui.SecondAnswer->setText(answer2);
    QString answer3 = QString::fromStdString(load["answer3"].s());
    ui.ThirdAnswer->setText(answer3);
    QString answer4 = QString::fromStdString(load["answer4"].s());
    ui.FourthAnswer->setText(answer4);

}

