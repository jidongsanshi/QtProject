#include "widget.h"
#include "ui_widget.h"
#include <Qtimer>
#include "QDebug"
#include "QMouseEvent"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1=startTimer(1000);//单位是毫秒
    id2=startTimer(2000);

    //定时器第二种方式
    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        //label4 每间隔0.5秒+1
        ui->label_4->setText(QString::number(num++));
    });

    //点击暂停 实现停止定时器
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer->stop();
    });

    //给label1安装事件过滤器
    //1安装事件过滤器
    ui->label->installEventFilter(this);



}
//2重写eventfilter事件
bool Widget::eventFilter(QObject *obj, QEvent *e){
    if(obj==ui->label){
        if(e->type() == QEvent::MouseButtonPress){
                QMouseEvent *ev = static_cast<QMouseEvent *>(e);
                qDebug()<<"事件过滤器中鼠标按下"<<ev->x()<<","<<ev->y();
                return true;
            }
    }

    return QWidget::eventFilter(obj,e);
}

void Widget::timerEvent(QTimerEvent *ev){
    static int num1 =1;
    //label2每隔一秒+1
    if(ev->timerId()==id1){
        ui->label_2->setText(QString::number(num1++));
    };
    //label3 每隔2秒+1
    static int num2 =1;
    if(ev->timerId()==id2){
        ui->label_3->setText(QString::number(num2++));
    }

}

Widget::~Widget()
{
    delete ui;
}
