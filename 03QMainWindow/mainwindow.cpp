#include "mainwindow.h"
#include "QMenuBar"
#include "QToolBar"
#include "QDebug"
#include "QPushButton"
#include"QStatusBar"
#include "QLabel"
#include "QDockWidget"
#include "QTextEdit"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1280,720);
    //菜单栏创建
    //菜单栏最多只能有一个

    QMenuBar *bar = menuBar();
    //将菜单栏放到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);
    //设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置不允许浮动
    toolBar->setFloatable(false);

    //设置移动（总开关）
    //toolBar->setMovable(false);

    toolBar->addAction("新建");
    toolBar->addSeparator();
    toolBar->addAction("打开");

    //工具栏添加控件
    QPushButton *btn = new QPushButton("a",this);
    toolBar->addWidget(btn);

    //状态栏 最多有一个
    QStatusBar *stBar = statusBar();
    //设置到窗口
    setStatusBar(stBar);
    //放标签控件
    QLabel *label = new QLabel("提示信息",this);
    stBar->addWidget(label);

    QLabel *label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);

    //铆接部件（浮动窗口）可以有多个
    QDockWidget *dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    //只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    //设置中心部件 只能有一个
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);


}

MainWindow::~MainWindow()
{

}
