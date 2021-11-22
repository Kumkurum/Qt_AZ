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

    Hexogon_Polygon=nullptr;                                                            //что бы не ругался компилятор что удаляем void  так там нулевой указатель будет

    P_Hexogon_Button->setAutoFillBackground(true);

    New_Hexogon_Polygon();

    P_Hexogon_Button->setText(Text_on_Button);//                                   устанавливаем текст на кнопку

    Change_Color("green");


    P_Hexogon_Button->installEventFilter(this);                                                       // перехватываем событие



    //(НА БУДУЮЩЕЕ
    Button_Menu = new QMenu(this);
    Button_Menu->addAction("&FUCK",this,SLOT(Change_Color_Fuel()));//меню для правого клика мыши пока пусто


    connect(P_Hexogon_Button,SIGNAL(clicked()),                                                     //связываем левый клик с функцией
            SLOT(Hexogon_Button_click()));

}
void Hexogon_Button::Change_Color(QString _Color ){                                             // функция изменения цвета

    P_Hexogon_Button->setStyleSheet("background-color: "+_Color+';'+
                                    "border-style: solid;");
}

void Hexogon_Button::Hexogon_Button_click(){                                                //функция левого клика мыши
    qDebug()<<"x = " +QString::number(X_Pos);                                                    //ДЛЯ ОТЛАДКИ
    qDebug()<<"x_New ="+QString::number(X_Pos_New);                                         //ДЛЯ ОТЛАДКИ

    if(Stage    ==   true)
        Change_Color("green");
    else
        Change_Color("red");
    Stage=!Stage;
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
    New_Hexogon_Polygon();                                                                                   //масштабируем все в кнопке

};

void Hexogon_Button::Set_Text(QString& _Text){          //функция установки переданного текста в кнопку
    Text_on_Button =_Text;
    P_Hexogon_Button->setText(Text_on_Button);
};


bool Hexogon_Button::eventFilter(QObject* p_obj,QEvent * p_event){                                          //перехватываем события в кнопке

    if(p_event->type()==QEvent::MouseButtonPress){                                          //перехватываем правый щелчёк мыши
        if(static_cast<QMouseEvent*>(p_event)->button()==Qt::RightButton){                                              //делаем допустимое привидение типа события к событию щелчка правой кнопки мыши


            Button_Menu->move(QCursor::pos());
            Button_Menu->show();
            qDebug()<<Nomer_TBC;
            return true;                                                                                                                //не пускаем дальше событие
        }
    }
    return false;                                                                                                                       //пускаем событие дальше
}

void Hexogon_Button::New_Hexogon_Polygon(){
    delete Hexogon_Polygon;//чистим память старого полигона, хотя вроде Qt сам все делает

    Hexogon_Polygon=new QPolygon{Hexogon_Points[0]*Multiplier,Hexogon_Points[1]*Multiplier,//используем static Qvector он один для всех кнопок и его масштабируя задаём как новый полигон
            Hexogon_Points[2]*Multiplier,Hexogon_Points[3]*Multiplier,
            Hexogon_Points[4]*Multiplier,Hexogon_Points[5]*Multiplier};

P_Hexogon_Button->setMask( *Hexogon_Polygon );

P_Hexogon_Button->resize( Show_Size.x() * Multiplier , Show_Size.y() * Multiplier );

P_Hexogon_Button->move(x*Multiplier -   (X_Pos)*(Multiplier-Start)  -(X_Pos_New-X_Pos)*(Multiplier),
                       y*Multiplier -   (Y_Pos)*(Multiplier-Start) -(Y_Pos_New-Y_Pos)*(Multiplier));

};

void Hexogon_Button::Change_Color_Fuel(){

    Change_Color( "rgb(0,200,10)");
}
