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
	auto numberofplayer = crow::json::load(r.text);
	
	if (numberofplayer["numberofplayer"] == 1) {
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
