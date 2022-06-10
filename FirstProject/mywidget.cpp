#include "mywidget.h"
#include "QPushButton"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->setText("第一个按钮");


    QPushButton *btn2 = new QPushButton("第二个按钮",this);

    //移动btn2 按钮
    btn2->move(100,100);

    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //点击第一个按钮 关闭窗口
    //connect(信号发出者,发送的信号(函数的地址),信号接受者,处理的槽函数)
    connect(btn2,&QPushButton::clicked,this,&myWidget::close);

}

myWidget::~myWidget()
{

}
