#include "myImage.h"

#include <QtWidgets>

MyImage::MyImage(QWidget *parent) : QWidget(parent)
{

}

void MyImage::setImage(QImage srcImage)
{
	image = srcImage;
	
	if (!image.isNull())
	{
		emit imageReady();
	}
}

void MyImage::setImage(QString fileName)
{
	if (!image.load(fileName))
	{
		throw std::exception("Cannot load image!");
	}

	if (scaledImage.isNull())
	{
		scaledImage = image;
	}

	emit imageReady();
}

QImage& MyImage::getImage()
{
	return image;
}

QImage& MyImage::getResizedImage()
{
	return scaledImage;
}

void MyImage::resizeQImage(QSize &labelSize)
{
	QSize newSize;

	if (image.isNull())
	{
		return;
	}

	if (image.size() == labelSize)
	{
		return;
	}
	else
	{
		double ar = double(image.size().width()) / double(image.size().height());

		double dFactorWidth = double(labelSize.width()) / double(image.size().width());
		double dFactorHeight = double(labelSize.height()) / double(image.size().height());

		if (dFactorWidth < dFactorHeight)
		{
			double newWidth = double(labelSize.width());
			double newHeight = newWidth / ar;

			newSize = QSize(newWidth, newHeight);
		}

		else if (dFactorWidth > dFactorHeight)
		{
			double newHeight = double(labelSize.height());
			double newWidth = newHeight *ar;

			newSize = QSize(newWidth, newHeight);
		}
	}

	scaledImage = image.scaled(newSize);

	emit imageReady();
}

Image2D<uchar>& MyImage::getImageFromQImage()
{
	
}