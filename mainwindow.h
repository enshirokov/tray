#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>



class MyTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    MyTray(QObject *parent = 0) : QSystemTrayIcon (parent) {}

protected:
    bool event(QEvent *event);

};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showMsg(QSystemTrayIcon::ActivationReason reason);
    void closeApp();

private:
    MyTray *trIcon;
    QAction *actClose;
    QMenu *menu;

};

#endif // MAINWINDOW_H
