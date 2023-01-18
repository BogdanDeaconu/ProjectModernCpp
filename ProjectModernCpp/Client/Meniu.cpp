#include "Meniu.h"
#include "Lobby.h"

Meniu::Meniu(QString username,QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    this->username = username.toUtf8().constData();
}

Meniu::~Meniu()
{}

void Meniu::on_StartGameButton_clicked()
{
	auto r=cpr::Put(cpr::Url{"http://localhost:18080/createLobby"},
        cpr::Body{ "&ownername=", username });
    if (r.status_code == 200)
    {
        Lobby* lobbypage = new Lobby();
        lobbypage->show();
    }
    else {
        QMessageBox::information(this, "Error","Lobby can t be created");
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
    std::string ownername = ui.lineEdit_2->text().toUtf8().constData();
    auto r = cpr::Post(cpr::Url{ "http://localhost:18080/joinLobby" },
        cpr::Body{ "&username="+username,"&gameOwner="+ownername});
    if (r.status_code == 200)
    {
        Lobby* lobbypage = new Lobby();
        lobbypage->show();
    }
    else {
        QMessageBox::information(this, "Error", "Lobby can t be found");
    }
}

void Meniu::on_ExitGameButton_clicked() {
	this->close();
}

void Meniu::on_HistoryButton_clicked()
{
	
}
