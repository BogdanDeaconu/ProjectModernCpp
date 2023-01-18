#include "Client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Client::~Client()
{}

void Client::on_SignUpButton_clicked()
{
	QString name = ui.UsernameLineEdit->text();
	QString password = ui.PasswordLineEdit->text();
	std::string aux = name.toUtf8().constData();
	std::string aux2 = password.toUtf8().constData();
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:18080/signupaccount" },
		cpr::Payload{
			{"username", aux},
		    {"password", aux2}
		}
	);
	if (response.status_code == 200) {
		Meniu* meniu = new Meniu(name);
		this->close();
		meniu->show();
		meniu->SetUserMeniu(name);
	}
	else {
		QMessageBox::information(this, "Error", "Account already exists");
	}
}

void Client::on_LogInButton_clicked()
{
    QString name = ui.UsernameLineEdit->text();
    QString password = ui.PasswordLineEdit->text();
	std::string aux = name.toUtf8().constData();
	std::string aux2 = password.toUtf8().constData();
	auto response = cpr::Post(
		cpr::Url{ "http://localhost:18080/loginaccount" },
		cpr::Payload{
			{"username" , aux},
			{"password" , aux2}
		}
	);
	if (response.status_code == 201) {
		Meniu* meniu = new Meniu(name);
		this->close();
		meniu->show();
		meniu->SetUserMeniu(name);
	}
	else {
		QMessageBox::information(this, "Error", "Account not found OR wrong password");
	}
}


