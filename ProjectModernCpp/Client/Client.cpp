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
		cpr::Parameters{
			{"username", aux},
		    {"password", aux2}
		}
	);
}

void Client::on_LogInButton_clicked()
{
    QString name = ui.UsernameLineEdit->text();
    QString password = ui.PasswordLineEdit->text();
	std::string aux = name.toUtf8().constData();
	std::string aux2 = password.toUtf8().constData();
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:18080/loginaccount" },
		cpr::Payload{
			{"username" , aux},
			{"password" , aux2}
		}
	);
	
}


