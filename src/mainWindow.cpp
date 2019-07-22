#include "mainWindow.h"
#include "myImage.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow),
	img(new MyImage)
{
	ui->setupUi(this);
	
	CreateActions();
}

MainWindow::~MainWindow()
{
	if (ui)
	{
		delete ui;
	}

	if (img)
	{
		delete img;
	}
}

void MainWindow::CreateActions()
{
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openImage()));

	//connect(this, SIGNAL(clicked()), this, SLOT(openImage()));
	connect(img, SIGNAL(imageReady()), this, SLOT(displayImage()));

	connect(ui->actionQuit, &QAction::triggered, qApp, QApplication::quit);
}

void MainWindow::openImage()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Select a file...", QDir::homePath(), "File Description (*.jpg)");

	img->setImage(fileName);	
}

void MainWindow::displayImage()
{
	ui->label->setPixmap(QPixmap::fromImage(img->getResizedImage()));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	img->resizeQImage(ui->label->size());

	QMainWindow::resizeEvent(event);

}

void MainWindow::displayHistogram()
{
	
}