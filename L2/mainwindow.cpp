#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->getColor = new QAction(tr("&Get Color"),this);
    getColor->setStatusTip(tr("Get a Color"));

    this->setColor = new QAction(tr("&Set Color"),this);
    setColor->setStatusTip(tr("Set a Color"));

    this->openAction = new QAction(tr("&Open"), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a file"));
    //openAction->setIcon(QIcon(":/123.jpg"));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *openB = new QToolBar(tr("&File"));
    openB->addAction(openAction);
    QToolBar *setColorB = new QToolBar(tr("&Get Color"));
    setColorB->addAction(setColor);
    QToolBar *getColorB = new QToolBar(tr("&Set Color"));
    getColorB->addAction(getColor);


    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(setColorB, SIGNAL(triggered()), this, SLOT(setAColor()));
    connect(getColorB,SIGNAL(triggered()),this,SLOT(getAColor()));


    msgLabel = new QLabel;
    msgLabel->setMinimumSize(msgLabel->sizeHint());
    msgLabel->setAlignment(Qt::AlignHCenter);
    statusBar()->addWidget(msgLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: Opx}"));

}

MainWindow::~MainWindow()
{ 
}

void MainWindow::open()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Image"),".",tr("Image Files(*.jpg *.png)"));
    if (path.length()==0)
        QMessageBox::information(NULL, tr("Error"), tr("No Files"));
    else
        QMessageBox::information(NULL, tr("Okay"), tr("in")+path);
}

void MainWindow::getAColor()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    QString msg = QString("r:  %1, g:  %2, b:  %3").arg(QString::number(color.red()), QString::number(color.green()), QString::number(color.blue()));
    QMessageBox::information(/*this这样位置就在之前的parent之内。。*/NULL, "Selected color", msg);
}

void MainWindow::setAColor()
{


}


