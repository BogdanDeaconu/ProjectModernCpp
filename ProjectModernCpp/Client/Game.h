#pragma once

#include <QMainWindow>
#include "ui_Game.h"
#include <qmessagebox.h>
#include <qstring.h>

#include <cpr/cpr.h>
#include <crow.h>

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent = nullptr);
	~Game();

private:
	Ui::GameClass ui;

private slots:
    void on_GetBool_clicked();

   
};