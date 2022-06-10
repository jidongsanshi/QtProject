#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QFile"
#include "QTextCodec"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击button选取文件

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path =QFileDialog::getOpenFileName(this,"打开文件","C:","(*.txt)");

        //将路径放在lineedit中
        ui->lineEdit->setText(path);

        //编码格式类
        QTextCodec *codec = QTextCodec::codecForName("gbk");
        //QFile默认支持的格式是UTF-8
        //读取内容放在 testEdit中
        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        QByteArray array = file.readAll();

//        QByteArray array=file.readLine();//按行读取

        //将读取的数据 放入textEdit中
        ui->textEdit->setText(array);
//        ui->textEdit->setText(codec->toUnicode(array));

    });
}

Widget::~Widget()
{
    delete ui;
}
