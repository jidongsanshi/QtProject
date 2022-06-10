#include "widget.h"
#include "ui_widget.h"
#include"QPushButton"
//Teacher类 老师类
//Student类 学生类
//下课后 老师会触发一个信号， 饿了，学生响应信号 请客吃饭


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->teacher=new Teacher(this);

    //创建一个学生对象
    this->student=new Student(this);

    //连接
//    connect(teacher,&Teacher::hungry,student,&Student::treat);

//    classOver();


    //连接带参数的信号和槽
    //函数指针指向函数地址

    void(Teacher:: *teacherSignal)(QString)=&Teacher::hungry;
    void(Student:: *studentSignal)(QString)=&Student::treat;
    connect(teacher,teacherSignal,student,studentSignal);
    //classOver();

    //点击按钮下课
    QPushButton *btn = new QPushButton("下课",this);
    this->resize(600,400);

    //点击按钮 触发下课
    //connect(btn,&QPushButton::clicked,this,&Widget::classOver);

    //无参信号连接槽

    void(Teacher:: *teacherSignal2)(void)=&Teacher::hungry;
    void(Student:: *studentSignal2)(void)=&Student::treat;
    connect(teacher,teacherSignal2,student,studentSignal2);

    //信号与信号连接
    connect(btn,&QPushButton::clicked,teacher,teacherSignal2);

    //信号断开
    //disconnect(teacher,teacherSignal2,student,studentSignal2);

    //Lambda表达式
    [=](){
        btn->setText("下课2");
    }();

    //利用Lambda表达式实现点击关闭窗口
    QPushButton *btn2 = new QPushButton;
    btn2->setText("close");
    btn2->move(300,0);
    btn2->setParent(this);
    connect(btn2,&QPushButton::clicked,this,[=](){
        this->close();
    });

}

Widget::~Widget()
{
    delete ui;
}
void Widget::classOver(){
    //下课函数 调用后 触发老师饿了信号
    //emit teacher->hungry();
    emit teacher->hungry("宫保鸡丁");
}
