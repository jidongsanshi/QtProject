#include "mylabel.h"
#include "QDebug"
#include "QMouseEvent"


MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
}
//void MyLabel::enterEvent(QEvent *event){
//    qDebug()<<"鼠标进入了";
//}

//void MyLabel::leaveEvent(QEvent *event){
//    qDebug()<<"鼠标离开了";
//}
//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev){
    qDebug()<<"鼠标按下"<<ev->x()<<","<<ev->y();
}

//鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    qDebug()<<"鼠标释放";
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    qDebug()<<"鼠标移动";
}

bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        qDebug()<<"Event函数中鼠标按下"<<ev->x()<<","<<ev->y();
        return true;
    }

    return QLabel::event(e);}

