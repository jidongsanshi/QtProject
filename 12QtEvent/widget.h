#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void timerEvent(QTimerEvent *);
    int id1;
    int id2;//定时器2 的唯一标识符

    bool eventFilter(QObject *, QEvent *);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
