#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionNew->setIcon(QIcon("E:/test.jpg"));
    //使用添加Qt资源":+前锥名+文件名"
    ui->actionNew->setIcon(QIcon(":/Image/test.jpg"));
    ui->actionOpen->setIcon(QIcon(":/Image/test2.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
