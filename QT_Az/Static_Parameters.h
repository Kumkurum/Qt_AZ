#ifndef STATIC_PARAMETERS_H
#define STATIC_PARAMETERS_H
#include "hexogon_button.h"

int Hexogon_Button::X_Pos {1466+85};
int   Hexogon_Button::Y_Pos {1078+100};
int Hexogon_Button::X_Pos_New {1466+85};
int   Hexogon_Button::Y_Pos_New {1078+100};
QPoint Hexogon_Button::Show_Size{170,200};
QVector<QPoint> Hexogon_Button::Hexogon_Points{
    QPoint(  0  ,150  )  ,QPoint(  0   , 50      ),
    QPoint( 85   , 0      )  ,QPoint( 170   ,   50 ),
    QPoint( 170   ,   150   )   ,QPoint(   85      ,   200    )};
QVector<QString> Hexogon_Button::TBC_Color= {                                                                   //варианты расцветки в зависимости от топлива
                                                                                                "rgb(100,200,200)",
                                                                                                "rgb(100,100,200)",
                                                                                                "rgb(100,20,100)",
                                                                                                "rgb(100,50,200)",
                                                                                                "rgb(100,255,200)",
                                                                                                "rgb(100,200,100)"};
 QVector<QString> Hexogon_Button::Fuel_Name={                                                                //название топлива
                                                                                            "Type_1",
                                                                                            "Type_2",
                                                                                            "Type_3",
                                                                                            "Type_4",
                                                                                            "Type_5",
                                                                                            "Type_6"
                           };

#endif // STATIC_PARAMETERS_H
