#ifndef LABEL_H
#define LABEL_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <QFont>

class MyLabel : public QLabel
{
public:
	MyLabel(QLabel *parent = 0);

	void SetQImage(const QImage &srcImg);

private:
	void resizeEvent(QResizeEvent *event);
};
#endif