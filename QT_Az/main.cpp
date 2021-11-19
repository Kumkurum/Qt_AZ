#include "mainwindow.h"

#include <QApplication>
int Hexogon_Button::X_Pos {1466+85};
int   Hexogon_Button::Y_Pos {1078+100};
int Hexogon_Button::X_Pos_New {1466+85};
int   Hexogon_Button::Y_Pos_New {1078+100};
QPoint Hexogon_Button::Show_Size{170,200};
QVector<QPoint> Hexogon_Button::Hexogon_Points{
    QPoint(  0  ,150  )  ,QPoint(  0   , 50      ),
    QPoint( 85   , 0      )  ,QPoint( 170   ,   50 ),
    QPoint( 170   ,   150   )   ,QPoint(   85      ,   200    )};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
