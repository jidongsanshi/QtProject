#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget控件
    //设置列数
    ui->tableWidget->setColumnCount(3);

    //设置表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("孙悟空"));

    QStringList namelist;
    namelist<<"孙悟空"<<"赵云"<<"张飞"<<"关羽"<<"花木兰";
    QStringList sexlist;
    sexlist<<"男"<<"男"<<"男"<<"男"<<"女";

    for(int i =0;i<5;i++){
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexlist[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    };

}

Widget::~Widget()
{
    delete ui;
}
