#include "Meniu.h"

Meniu::Meniu(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

Meniu::~Meniu()
{}

void Meniu::on_StartGameButton_clicked()
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/playerstartgame" });
	auto load = crow::json::load(r.text);
	int numberofplayers = load["numberofplayers"].i();
	if (numberofplayers == 1) {
		QMessageBox::information(this, "Error", "Game started, Wait for players");
	}
	else {
		QMessageBox::information(this, "Error", "Game can t start");
	}
}

void Meniu::SetUserMeniu(QString username)
{
	//ui.HomePage->setText(qstringUser);
	ui.Account->setText(username);
	ui.Wins->setText("Wins: 0");
	ui.Wins->setFont(QFont("Times", 12, QFont::Bold, false));
	ui.lineEdit_5->setText("Losses: 0");
	ui.lineEdit_5->setFont(QFont("Times", 12, QFont::Bold, false));
	ui.Account->setFont(QFont("Times New Roman", 20, QFont::Bold, false));
}

void Meniu::on_EnterGameButton_clicked()
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/playerjoingame" });
	auto load = crow::json::load(r.text);
	int nuberofplayer = load["numberofplayers"].i();
	if (nuberofplayer == 2) {
		QMessageBox::information(this, "Error", "Game started, Wait for players");
	}
	else {
		QMessageBox::information(this, "Error", "Game can t start");
	}

}

void Meniu::on_ExitGameButton_clicked() {
	this->close();
}

void Meniu::on_HistoryButton_clicked()
{
	
}
