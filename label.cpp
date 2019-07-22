#include "label.h"

MyLabel::MyLabel(QLabel *parent) :QLabel(parent)
{ 
	this->setPixmap(QPixmap());
}

void MyLabel::SetQImage(const QImage &srcImg)
{
	this->setPixmap(QPixmap::fromImage(srcImg));
}

void MyLabel::resizeEvent(QResizeEvent *event)
{	
	if (!this->pixmap()->isNull())
	{
		double ar = double(this->pixmap()->width()) / double(this->pixmap()->height());

		double dFactorWidth = double(this->width()) / double(this->pixmap()->width());
		double dFactorHeight = double(this->height()) / double(this->pixmap()->height());

		if (dFactorWidth < dFactorHeight)
		{
			double newWidth = double(this->width());
			double newHeight = newWidth / ar;

			//this->pixmap()->scaled(newWidth, newHeight);
		}

		else if (dFactorWidth > dFactorHeight)
		{
			double newHeight = double(this->height());
			double newWidth = newHeight *ar;

			//this->pixmap()->scaled(newWidth, newHeight);
		}
	}

	else
	{
		return; 
	}
}