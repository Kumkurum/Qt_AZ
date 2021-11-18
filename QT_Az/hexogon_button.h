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
    QPalette Hexogon_Palette;
    bool Stage;
    int x;
    int y;
    float Multiplier ;
    float Start;
    QString Text_on_Button;
    void New_Hexogon_Polygon();

public:
    static QPoint Show_Size;
    static QVector<QPoint> Hexogon_Points;
    QPushButton* P_Hexogon_Button;
    static int X_Pos;
    static int Y_Pos;
    static int X_Pos_New;
    static int Y_Pos_New;

    Hexogon_Button(const int &, const int &,  const float & , QMainWindow& ,QString&);
    void Change_Color(QString );
    int Nomer_TBC;
    void Hexogon_Button_resize(bool);
    void Set_Text(QString&);


public slots:

    void Hexogon_Button_click();

signals:

};
