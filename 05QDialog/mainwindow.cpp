#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDialog"
#include "QDebug"
#include "QMessageBox"
#include "QColorDialog"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮弹出一个对话框
    connect(ui->actionNew,&QAction::triggered,[=](){
        //对话框 分类
        //模态对话框（不可对其他窗口进行操作） 非模态对话框（可以对其他窗口进行操作）
        //模态创建 阻塞
//        QDialog dlg(this);
//        dlg.resize(200,100);
//        dlg.exec();

//        qDebug()<<"模态对话框弹出了";

        //非模态对话框
//        QDialog dlg2(this);
//        dlg2.resize(200,100);
//        dlg2.show();
//        dlg2.exec();
//        QDialog *dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);

        //消息对话框
       //参数1 父亲 2 标题 3提示内容 4 按键类型 5 默认回车关联按键
       //错误对话框
//     QMessageBox::critical(this,"critical","错误");

        //信息对话框
//         QMessageBox::information(this,"info","信息");
        //问题对话框
//         if(QMessageBox::Save==QMessageBox::question(this,"question","问题",QMessageBox::Save|QMessageBox::Cancel)){
//             qDebug()<<"save";
//         }
        //警告对话框
//        QMessageBox::warning(this,"warning","警告");

        //其他对话框
        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug()<<color.blue();

        //文件对话框
        QString str =QFileDialog::getOpenFileName(this,"打开文件","C:","(*.txt)");
        qDebug()<<str;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
