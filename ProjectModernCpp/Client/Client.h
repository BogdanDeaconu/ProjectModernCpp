#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include <qstring.h>
#include "ui_Client.h"

#include <cpr/cpr.h>
#include <crow.h>

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private:
	Ui::ClientClass ui;
	QMessageBox box;


private slots:
	void on_SignUpButton_released();
	void on_SignUpButton_clicked();

	void on_LogInButton_released();
	void on_LogInButton_clicked();
};
