#pragma once

#include <QMainWindow>
#include "ui_Meniu.h"
#include <qmessagebox.h>
#include <qstring.h>

#include <cpr/cpr.h>
#include <crow.h>

class Meniu : public QMainWindow
{
	Q_OBJECT

public:
	Meniu(QString username,QWidget *parent = nullptr);
	~Meniu();

private:
    Ui::MeniuClass ui;
    std::string username;
public:
	void SetUserMeniu(QString username);
	
private slots:
	void on_StartGameButton_clicked();
	void on_EnterGameButton_clicked();
	void on_ExitGameButton_clicked();
	void on_HistoryButton_clicked();
    
};
