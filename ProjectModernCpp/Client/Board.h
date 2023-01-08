#pragma once

#include <QMainWindow>
#include "ui_Board.h"

class Board : public QMainWindow
{
	Q_OBJECT

public:
	Board(QWidget *parent = nullptr);
	~Board();

private:
	Ui::BoardClass ui;
private slots:
    void on_PushButton_clicked();
    void on_PushButton2_clicked();
    void on_PushButton3_clicked();
    void on_PushButton4_clicked();
    void on_PushButton5_clicked();
    void on_PushButton6_clicked();
    void on_PushButton7_clicked();
    void on_PushButton8_clicked();
    void on_PushButton9_clicked();
    void on_PushButton10_clicked();
    void on_PushButton11_clicked();
    void on_PushButton12_clicked();
};
