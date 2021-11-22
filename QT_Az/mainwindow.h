#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "hexogon_button.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QWidget>
#include<QWheelEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Hexogon_Button *Active_Zone[163];

        QFile *File_Name;

    void Parser(QFile &_File);

private:


    void Menu_Main_Window();

    void wheelEvent(QWheelEvent*);
    Ui::MainWindow *ui;
public slots:

    void Brows();
    void Scan();
};
#endif // MAINWINDOW_H
