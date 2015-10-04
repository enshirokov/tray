#include "mainwindow.h"
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

bool MyTray::event(QEvent *event)
{
    qDebug() << "event";
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    qDebug() << "mainwindow create";

    //this->setWindowFlags( Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    // necessary if you want to track when you enter and leave the widget's rect with the mouse
    this->setMouseTracking(true);

    actClose = new QAction("Close", this);
    connect(actClose, &QAction::triggered, this, &MainWindow::closeApp);



    this->menuBar()->setNativeMenuBar(false);
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(actClose);

    trIcon = new MyTray(this);
    trIcon->setIcon(QIcon(":/main_icon.png"));
    trIcon->setContextMenu(menu);


    connect(trIcon, &QSystemTrayIcon::activated, this, &MainWindow::showMsg);

    trIcon->show();


}

MainWindow::~MainWindow()
{
}

void MainWindow::showMsg(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "show message";
    trIcon->showMessage("tray", "Message");

}

void MainWindow::closeApp()
{
    qDebug() << "Close app";
    close();
}
