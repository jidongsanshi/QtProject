#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);

    //设置画笔颜色
    QPen pen(QColor(255,0,0));

    //设置画笔宽度

   pen.setWidth(3);

   //拿起画笔
    painter.setPen(pen);



    //画线
    painter.drawLine(QPoint(0,0),QPoint(100,100));

    //画圆(椭圆)
    painter.drawEllipse(QPoint(100,100),50,50);
    //画矩形
    painter.drawRect(QRect(20,20,50,50));

    //画文字
    painter.drawText(QRect(10,200,100,50),"C++是最好的语言");
}

Widget::~Widget()
{
    delete ui;
}
