#include "hexogon_button.h"
//Принимаем в контруктор Позицию по Х У переменную масштабирования, окно отрисовки и номер ТВС
Hexogon_Button::Hexogon_Button( const int &_x_position, const int &_y_position,  const float &_Multi , QMainWindow& Windows_widget,QString &_nomber){

    Text_on_Button=_nomber;
    Stage  = false;
    Multiplier =_Multi;
    Start=_Multi;
    x=_x_position;
    y=_y_position;

    P_Hexogon_Button = new QPushButton(&Windows_widget);

    P_Hexogon_Button->setAutoFillBackground(true);
    //        Hexogon_Polygon = new QPolygon{QVector<QPoint>{ QPoint(  0 * Multiplier ,100 *Multiplier )  ,QPoint(  50 *  Multiplier  , 15    *   Multiplier  ),
    //                QPoint( 150 *   Multiplier  , 15    *   Multiplier  )  ,QPoint( 200 *   Multiplier  ,   100 *   Multiplier),
    //                QPoint( 150 *   Multiplier  ,   185 *   Multiplier  )   ,QPoint(   50  * Multiplier    ,   185  *   Multiplier  )}};



    Hexogon_Polygon = new QPolygon{QVector<QPoint>{ QPoint(  0 * Multiplier ,150 *Multiplier )  ,QPoint(  0 *  Multiplier  , 50    *   Multiplier  ),
            QPoint( 85 *   Multiplier  , 0    *   Multiplier  )  ,QPoint( 170 *   Multiplier  ,   50 *   Multiplier),
            QPoint( 170 *   Multiplier  ,   150 *   Multiplier  )   ,QPoint(   85  * Multiplier    ,   200  *   Multiplier  )}};//                  создание шестигранника по координатам

    P_Hexogon_Button->setText(Text_on_Button);//                    устанавливаем текст на кнопку

           Change_Color("green");

    P_Hexogon_Button->setMask(*Hexogon_Polygon);                                            // вырезаем на кнопке полигон
    P_Hexogon_Button->move(_x_position*Multiplier,_y_position*Multiplier);                                                                            //передвигаем кнопку на её место
    P_Hexogon_Button->resize(170*Multiplier,200*Multiplier);                                //изменяем размеры в соответсвии с масштабом

    P_Hexogon_Button->installEventFilter(this);                                                       // перехватываем событие

    connect(P_Hexogon_Button,SIGNAL(clicked()),                                                     //связываем левый клик с функцией
            SLOT(Hexogon_Button_click()));

}
void Hexogon_Button::Change_Color(QString _Color ){                                             // функция изменения цвета

    P_Hexogon_Button->setStyleSheet("background-color: "+_Color+';'+
                                    "border-style: solid;");
}

void Hexogon_Button::Hexogon_Button_click(){                                //функция левого клика мыши
    qDebug()<<"x = " +QString::number(X_Pos);                                           //ДЛЯ ОТЛАДКИ
    qDebug()<<"x_New ="+QString::number(X_Pos_New);                                         //ДЛЯ ОТЛАДКИ

        //    X_Pos=x;                                                                                            //сохраняем координаты кнопки что бы масштабироваться относительно неё
    //   Y_Pos=y;
    P_Hexogon_Button->setMask(*Hexogon_Polygon);
    if(Stage    ==   true)
        Change_Color("green");
    else
         Change_Color("red");
    Stage=!Stage;
    //  setFocusPolicy(Qt::StrongFocus);
}
void Hexogon_Button::Hexogon_Button_resize(bool sign){                              //функция масштабирования кнопок
    //Start=Multiplier;
    if (sign)
        Multiplier  +=    0.1;
    else{

        Multiplier  -=    0.1;
        if (Multiplier<0.3)
            Multiplier=0.3;
    }

    //масштабируем все в кнопке

    Hexogon_Polygon = new QPolygon{QVector<QPoint>{ QPoint(  0 * Multiplier ,150 *Multiplier )  ,QPoint(  0 *  Multiplier  , 50    *   Multiplier  ),
            QPoint( 85 *   Multiplier  , 0    *   Multiplier  )  ,QPoint( 170 *   Multiplier  ,   50 *   Multiplier),
            QPoint( 170 *   Multiplier  ,   150 *   Multiplier  )   ,QPoint(   85  * Multiplier    ,   200  *   Multiplier  )}};

    P_Hexogon_Button->setMask( *Hexogon_Polygon );

    P_Hexogon_Button->resize( 170 * Multiplier , 200 * Multiplier );

    P_Hexogon_Button->move(x*Multiplier -   (X_Pos)*(Multiplier-Start)  -(X_Pos_New-X_Pos)*(Multiplier),
                           y*Multiplier -   (Y_Pos)*(Multiplier-Start) -(Y_Pos_New-Y_Pos)*(Multiplier));


};

void Hexogon_Button::Set_Text(QString& _Text){          //функция установки переданного текста в кнопку
    Text_on_Button =_Text;
    P_Hexogon_Button->setText(Text_on_Button);
};


bool Hexogon_Button::eventFilter(QObject* p_obj,QEvent * p_event){                                          //перехватываем события в кнопке

    if(p_event->type()==QEvent::MouseButtonPress){                                          //перехватываем правый щелчёк мыши
        if(static_cast<QMouseEvent*>(p_event)->button()==Qt::RightButton){                                              //делаем допустимое привидение типа события к событию щелчка правой кнопки мыши

            X_Pos_New=x+85;
            Y_Pos_New=y+100;

            qDebug()<<Nomer_TBC;
            return true;                                                                                                                //не пускаем дальше событие
        }
    }
    return false;                                                                                                                       //пускаем событие дальше
}
















