#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <QMainWindow>
#include <opencv2/opencv.hpp>

#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <QFont>
#include "label.h"

class MyInterface : public QMainWindow
{
	Q_OBJECT;

public:
	MyInterface(QWidget *parent = 0);
	~MyInterface();

	cv::Mat img;

private slots:
	void open_image();

public:
	void button_open();
	void button_quit();
	void label_image();

	void resizeImage();
	void displayImage();

	void resizeEvent(QResizeEvent *event);

private:
	QGridLayout *planesGrid;
	QPushButton *quit;
	QPushButton *image;
	//QLabel *show_image;
	MyLabel *show_image;

	QImage qImg;
};
#endif