#ifndef MYIMAGE_H
#define MYIMAGE_H

#include "ui_interface.h"
#include "image2dTempl.hpp"
#include <opencv2\opencv.hpp>

class Statistics;
class MyImage: public QWidget
{
	Q_OBJECT
public:
	MyImage(QWidget *parent = 0);

private:
	QImage image;
	QImage scaledImage;

	cv::Mat matImg;
	Statistics *histogram;

public:
	void setImage(QImage srcImage);
	void setImage(QString fileName);
	QImage& getImage();
	QImage& getResizedImage();

	void resizeQImage(QSize &labelSize);

	Image2D<uchar>& getImageFromQImage();


signals:
	void imageReady();
};

#endif