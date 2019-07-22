#include "interface.h"

MyInterface::MyInterface(QWidget *parent)
	: QMainWindow(parent)
{
	this->setMinimumSize(640,480);
	
	planesGrid = new QGridLayout();
	planesGrid->setContentsMargins(5, 5, 5, 5);
	
	image = new QPushButton("Open Image", this);
	button_open();
	quit = new QPushButton("Quit", this);
	button_quit();
	//show_image = new QLabel("Image", this);
	show_image = new MyLabel;
	label_image();

	planesGrid->addWidget(quit, 0, 0);
	planesGrid->addWidget(image, 0, 1);
	planesGrid->addWidget(show_image, 1, 0);

	QWidget *window = new QWidget(this);
	window->setLayout(planesGrid);

	this->showMaximized();
	this->setCentralWidget(window);

	this->show();
}

MyInterface::~MyInterface()
{
	if (planesGrid)
	{
		delete planesGrid;
	}

	if (quit)
	{
		delete quit;
	}

	if (image)
	{
		delete image;
	}

	if (show_image)
	{
		delete show_image;
	}
}

void MyInterface::button_open()
{
	image->setFont(QFont("Arial", 15, QFont::Bold));
	connect(image, SIGNAL(clicked()), this, SLOT(open_image()));
}

void MyInterface::button_quit()
{
	quit->setFont(QFont("Arial", 15, QFont::Bold));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MyInterface::label_image()
{
	show_image->setMinimumSize(show_image->maximumSize());
}

void MyInterface::open_image()
{
	/*if (qImg.load("../Desert.jpg") == false)
	{
		throw std::exception("Cannot load image!");
	}*/

	img = cv::imread("../Desert.jpg");
	cv::cvtColor(img, img, CV_BGR2RGB);

	//resizeImage();
	displayImage();
	
}

void MyInterface::displayImage()
{
	qImg = QImage((const unsigned char*)img.data, img.cols, img.rows, QImage::Format_RGB888);
	qImg = qImg.scaled(show_image->width() , show_image->height(), Qt::KeepAspectRatio);
	
	//show_image->setPixmap(QPixmap::fromImage(qImg));
	show_image->SetQImage(qImg);
}

void MyInterface::resizeEvent(QResizeEvent *event)
{
	displayImage();
}

void MyInterface::resizeImage()
{
	if (img.size().width > show_image->width() || img.size().height > show_image->height())
	{
		double ar = double(img.size().width) / double(img.size().height);

		double dFactorWidth = double(show_image->width()) / double(img.size().width);
		double dFactorHeight = double(show_image->height()) / double(img.size().height);

		if (dFactorWidth < dFactorHeight)
		{
			double newWidth = double(show_image->width());
			double newHeight = newWidth / ar;

			cv::resize(img, img, cv::Size(newWidth, newHeight));
		}

		else if (dFactorWidth > dFactorHeight)
		{
			double newHeight = double(show_image->height());
			double newWidth = newHeight *ar;

			cv::resize(img, img, cv::Size(newWidth, newHeight));
		}	
	}
}

