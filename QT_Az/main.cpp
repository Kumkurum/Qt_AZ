#include "mainwindow.h"

#include <QApplication>
int Hexogon_Button::X_Pos =1466+85;
int   Hexogon_Button::Y_Pos =1078+100;
int Hexogon_Button::X_Pos_New =1466+85;
int   Hexogon_Button::Y_Pos_New =1078+100;

QPolygonF Hexogon_Button::Hexogon_Polygon_Point {QVector<QPointF>{
    QPointF(  0  ,150  )  ,QPointF(  0   , 50      ),
    QPointF( 85   , 0      )  ,QPointF( 170   ,   50 ),
    QPointF( 170   ,   150   )   ,QPointF(   85      ,   200    )}};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
