#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "hexogon_button.h"
#include <QWidget>
#include<QWheelEvent>
//#include<QTextCodec>

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
    void Parser(QFile &_File);
    QFile *File_Name;
private:

    void wheelEvent(QWheelEvent*);
    Ui::MainWindow *ui;
public slots:

    void Brows();
    void Scan();
};
#endif // MAINWINDOW_H
