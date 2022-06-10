#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TreeWidget树控件使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem *liitem= new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *minitem= new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhiitem= new QTreeWidgetItem(QStringList()<<"智力");
    //加载顶层结点
    ui->treeWidget->addTopLevelItem(liitem);
    ui->treeWidget->addTopLevelItem(minitem);
    ui->treeWidget->addTopLevelItem(zhiitem);
    QStringList heroL1;
    heroL1<<"万豪"<<"能抗能打";
    QTreeWidgetItem *l1= new QTreeWidgetItem(heroL1);
    liitem->addChild(l1);

}

Widget::~Widget()
{
    delete ui;
}
