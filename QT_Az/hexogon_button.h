#pragma once
#include <QMainWindow>
#include <QtWidgets>
#include<QWheelEvent>
class Hexogon_Button  : public QPushButton{
    Q_OBJECT
protected:
    virtual bool eventFilter(QObject*,QEvent*);
private:
    QPolygon* Hexogon_Polygon;

    bool Stage;
    int x;
    int y;
    float Multiplier ;
    float Start;
    QString Text_on_Button;
    QMenu *Button_Menu;

    void New_Hexogon_Polygon();

public:
    Hexogon_Button(const int &, const int &,  const float & , QMainWindow& ,QString&);

    static QPoint Show_Size;
    static QVector<QPoint> Hexogon_Points;
    static int X_Pos;
    static int Y_Pos;
    static int X_Pos_New;
    static int Y_Pos_New;

    int Nomer_TBC;

    QPushButton* P_Hexogon_Button;


    void Change_Color(QString );
    void Hexogon_Button_resize(bool);
    void Set_Text(QString&);


public slots:
    void Change_Color_Fuel();
    void Hexogon_Button_click();

signals:

};
