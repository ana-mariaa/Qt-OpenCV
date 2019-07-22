#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_interface.h"

class MyImage;

class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void openImage();
	void displayImage();

	void displayHistogram();

private:
	Ui::MainWindow *ui;
	MyImage *img;
	
	void CreateActions();

	void resizeEvent(QResizeEvent *event) override;
};


#endif