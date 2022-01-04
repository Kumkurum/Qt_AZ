#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString Avv="fuck";
    int nomer_TBC = 0;
    int Number[]{ 24,21,20,19,18,17,16,17,16,17,18,19,20,21,24 };   //для определения координат кнопок в строке
    int Iter_Count[] = { 6, 9, 10, 11, 12, 13, 14, 13, 14, 13, 12, 11, 10, 9, 6 };//число кнопок в строке
    int X_Coord_Start []= { 850  ,   586 ,    498 ,    410 ,    322 ,    234 ,    146 ,    234  ,  146    ,  234  ,  322 ,    410 ,    498 ,    586 ,    850 };// стартовые координаты по высоте

    Menu_Main_Window();//метод создания меню

    for (int Iter_Hight = 0 ; Iter_Hight < 15  ;Iter_Hight ++ ) {

        for (int Iter_Wight = 0     ;   Iter_Wight  <   Iter_Count  [   Iter_Hight  ] ; Iter_Wight++ ) {

            Avv=QString::number( Iter_Hight + 1 )+'-'+QString::number( Number[ Iter_Hight ] + Iter_Wight *   2)+'\n'+'\n'+QString::number(   nomer_TBC   +   1   );
            Active_Zone[ nomer_TBC ] = new Hexogon_Button( X_Coord_Start[ Iter_Hight ] + 176 * ( Iter_Wight + 1 )   ,   2310 - 154 * ( Iter_Hight + 1 ) , 0.3  ,   *this   ,   Avv );
            Active_Zone[ nomer_TBC ]->Nomer_TBC = nomer_TBC + 1;
            nomer_TBC++;

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::wheelEvent(    QWheelEvent *   pe ){       //попытка по прокрутке колёсика увеличивать или уменьшать область Активной Зоны
    QPoint nAngle = pe->angleDelta();

    if(nAngle.y() > 0)
        for (int Iter = 0 ; Iter < 163 ; Iter++){

            Active_Zone[Iter]->Hexogon_Button_resize(1);//увеличение масштаба
        }
    if (nAngle.y()< 0 )
        for (int Iter = 0 ; Iter < 163 ; Iter++)
            Active_Zone[Iter]->Hexogon_Button_resize(0);//уменьшение масштаба
};

void MainWindow::Brows(){                                                   //функция открытия директории
    QString str=QFileDialog::getOpenFileName(0,
                                             "Select a Directory");
    File_Name = new QFile(str);                                             //Создаём файл с путём str

    //QFileDialog::getOpenFileName()
}


//void MainWindow::Scan(){                                                //функция считывания данных с текстового файла
//    QTextStream File_Text(File_Name);                           //создаём поток и передаём в него наш файл
//    File_Name->open(QIODevice::ReadOnly);               //открываем файл для чтения
//    QChar _Index_of_Separate = '\t';                                //используем разделитель между данными в даненом случае /////ТАБУЛЯЦИЯ/////
//    const int Size_Param =4;
//    //СТОИТ УЛУЧШИТЬ И СДЕЛАТЬ АВТОМАТИЧЕСКИЙ ПОДСЧЁТ КОЛЛИЧЕСТВА ПАРАМЕТРОВ В ТЕКТОВОМ ФАЙЛЕ ИЛИ СДЕЛАТЬ БАЗУ ДАННЫХ
//    QVector<QString> *Param = new QVector<QString>[Size_Param];              //массив из 4 векторов для считывания данных, их может быть и больше вопрос к программе


//    QString Liner;              //для записи полной строки, так как считываем всю строку
//    QString Str;                    //для записи нудного параметра
//    QString Color_Nucler;
//    while  (!File_Text.atEnd()){                                                                                                                                                    //считываем данные до конца файла
//        Liner   = File_Text.readLine();                                                                                                                                             //построчно считываем данные
//        for (int  i =0;  i <Size_Param ; i++ ) {                                                                                                                                                         //смотря сколько параметров столько раз и считываем

//            Param[i].append( Liner.left(    Liner.indexOf(  _Index_of_Separate    )   ));                                       //копируем до знака табуляции копируем
//            //добавляем в базу значение параметра

//            Liner   = Liner.remove(    0,Liner.indexOf(    _Index_of_Separate  )+1);                                         //сжигаем из строки пройденный параметр

//        }
//    }
//    File_Name->close();                                                                                                                                                                     //закрываем файл, так как считали всё что нужно
//    QString Param_All;                                                                                                                                                                      //строка для считывания


//    //Для нахождение данных для конкретной кнопки будем пробегать по всем кнопкам и по всем данным в файле

//    //ТРЕБУЕТСЯ УЛУЧШИТЬ//// (НА БУДУЮЩЕЕ)
//    for (int Iter_in_Button=0; Iter_in_Button < 163;Iter_in_Button++ ) {                                                         //пробегаем по всем кнопкам их 163
//        for (int Iter_in_File = 0 ; Iter_in_File < 163 ;Iter_in_File++ ) {                                                            // пробегаем по всем данным по кнопкам в файле

//            if ( Active_Zone[Iter_in_Button]->Nomer_TBC == Param[1][Iter_in_File].toInt()){                                                 //если совпадают то добавляем все параметры  на кнопку
//                for (int Iter_Param = 0 ;Iter_Param < 4 ;Iter_Param++ ) {
//                    Param_All.append(Param[Iter_Param][Iter_in_File]).append('\n');
//                }

//                Active_Zone[Iter_in_Button]->Set_Text(Param_All);                                                                   //конкретно добавление на конпку текста
//                Param_All.clear();                                                                                                                                                                      //отчитска переменной для следующей кнопки

//                for (        int Iter_Color=0      ;     Iter_Color   <    Active_Zone[Iter_in_Button]->TBC_Color.count()    ;    Iter_Color++     )            //изменяем цвет кнопки в зависимости от типа топлива
//                    if(Param[2][Iter_in_File].contains( Active_Zone[Iter_in_Button]->Fuel_Name[Iter_Color]))
//                        Active_Zone[Iter_in_Button]->Change_Color(Active_Zone[Iter_in_Button]->TBC_Color[Iter_Color]);                                             //для этого для каждого обьекта кнопки вызвываем метод изменения цвета
//            }
//        }
//    }
//}

void MainWindow::Scan(){




}


QVector<QString> * MainWindow::Parsing_Parameters( const int _Count_Parameters,  const int _Delete_Lines ,QChar _Index_of_Separate){
    QTextStream File_Text(File_Name);                           //создаём поток и передаём в него наш файл
    File_Name->open(QIODevice::ReadOnly);               //открываем файл для чтения
    // _Index_of_Separate = '\t';                                //используем разделитель между данными в даненом случае /////ТАБУЛЯЦИЯ/////
    //  const int Size_Param =4;
    //СТОИТ УЛУЧШИТЬ И СДЕЛАТЬ АВТОМАТИЧЕСКИЙ ПОДСЧЁТ КОЛЛИЧЕСТВА ПАРАМЕТРОВ В ТЕКТОВОМ ФАЙЛЕ ИЛИ СДЕЛАТЬ БАЗУ ДАННЫХ
    QVector<QString> *Param = new QVector<QString>[_Count_Parameters];              //массив из векторов для считывания данных, их может быть и больше вопрос к программе
        File_Text.readLine(_Delete_Lines);


    QString Line;              //для записи полной строки, так как считываем всю строку

    while  (!File_Text.atEnd()){                                                                                                                                                    //считываем данные до конца файла
        Line   = File_Text.readLine();                                                                                                                                             //построчно считываем данные
        for (int  i =0;  i <_Count_Parameters ; i++ ) {                                                                                                                                                         //смотря сколько параметров столько раз и считываем

            Param[i].append( Line.left(    Line.indexOf(  _Index_of_Separate    )   ));                                       //копируем до знака табуляции копируем
            //добавляем в базу значение параметра

            Line   = Line.remove(    0,Line.indexOf(    _Index_of_Separate  )+1);                                         //сжигаем из строки пройденный параметр

        }
    }

    File_Name->close();                                                                                                                                                                     //закрываем файл, так как считали всё что нужно



    return Param;
}
void MainWindow::Save_Parameters(QVector<QString> *_Output_Data,QVector<QString> * _File_Data,QVector<QString> &_Name_Parameters){
    for (int Parameters_Iterator=0    ;   Parameters_Iterator   <   _Name_Parameters.count() ; Parameters_Iterator++) {


        for (int TBC_Iter=0; TBC_Iter<163; TBC_Iter++) {

            _Output_Data[Parameters_Iterator][TBC_Iter]=_File_Data[Parameters_Iterator][TBC_Iter];

        }
    }



}
void MainWindow::Menu_Main_Window(){

    //////меню
    ///

    QMenu *General ;//создание выподающего меню с вариантами ниже


    QMenu* Options;//второе выпадающее меню, ПОКА ПУСТО (НА БУДУЮЩЕЕ)
    //пиши как первое
    QAction *First_Option= new QAction("&First",this);
    QAction *Second_Option = new QAction("&Second",this);


    General = menuBar()->addMenu("&General");
    General->addAction("&Quit",//первый параметр это название сигнала & это горячая клавиша
                       this,//связывает с объектом этим-то
                       QApplication::quit//вот этим слотом
                       );// тут можно передать 4 параметром горячую клавишу
    General->addAction("&Archive",this,SLOT(Brows()));
    General->addAction("&Fuel_Tipy",this,&MainWindow::Scan);




    Options= menuBar()->addMenu("&Options");
    Options->addAction(First_Option);
    Options->addAction(Second_Option);

    //// сделать класс меню!

};

