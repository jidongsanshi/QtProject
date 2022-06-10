#include "widget.h"
#include "ui_widget.h"
#include "QDebug"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单元按钮 男默认选中
    ui->rBtnMan->setChecked(true);
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"woman";
    });

    connect(ui->cBoxWH,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });
    //利用listWidget写诗
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //将第一行诗放入listWidget中
    ui->listWidget->addItem(item);
}

Widget::~Widget()
{
    delete ui;
}
