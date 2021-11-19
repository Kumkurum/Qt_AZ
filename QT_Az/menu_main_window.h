#ifndef MENU_MAIN_WINDOW_H
#define MENU_MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QApplication>
#include <QMenuBar>

class Menu_Main_Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu_Main_Window(QMainWindow *parent = nullptr);

signals:

};

#endif // MENU_MAIN_WINDOW_H
