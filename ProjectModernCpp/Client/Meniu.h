#pragma once

#include <QMainWindow>
#include "ui_Meniu.h"

class Meniu : public QMainWindow
{
	Q_OBJECT

public:
	Meniu(QWidget *parent = nullptr);
	~Meniu();

private:
	Ui::MeniuClass ui;
};
