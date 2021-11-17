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

    for (int Iter_Hight = 0 ; Iter_Hight < 15  ;Iter_Hight ++ ) {

        for (int Iter_Wight = 0     ;   Iter_Wight  <   Iter_Count  [   Iter_Hight  ] ; Iter_Wight++ ) {

            Avv=QString::number( Iter_Hight + 1 )+'-'+QString::number( Number[ Iter_Hight ] + Iter_Wight *   2)+'\n'+'\n'+QString::number(   nomer_TBC   +   1   );
            Active_Zone[ nomer_TBC ] = new Hexogon_Button( X_Coord_Start[ Iter_Hight ] + 176 * ( Iter_Wight + 1 )   ,   2310 - 154 * ( Iter_Hight + 1 ) , 0.3  ,   *this   ,   Avv );
            Active_Zone[ nomer_TBC ]->Nomer_TBC = nomer_TBC + 1;
            nomer_TBC++;

        }
    }
    connect(ui->Scan,SIGNAL(clicked()),SLOT(Scan()));           //Связывание кнопки  считывания информации с тектового файла
    connect(ui->Brows,SIGNAL(clicked()),SLOT(Brows()));     //Связывание кнопки открытия поиска директории



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
                                             "Select a Directory",
                                             ui->File_Path->text());                //присваиваем путь к файлу в str
    File_Name = new QFile(str);                                             //Создаём файл с путём str
    ui->File_Path->setText(str);                                            //выводим путь к файлу в лэйбл
    //QFileDialog::getOpenFileName()
}


void MainWindow::Scan(){                                                //функция считывания данных с текстового файла
    QTextStream File_Text(File_Name);                           //создаём поток и передаём в него наш файл
    File_Name->open(QIODevice::ReadOnly);               //открываем файл для чтения
    QChar _Index_of_Separate = '\t';                                //используем разделитель между данными в даненом случае /////ТАБУЛЯЦИЯ/////

    //СТОИТ УЛУЧШИТЬ И СДЕЛАТЬ АВТОМАТИЧЕСКИЙ ПОДСЧЁТ КОЛЛИЧЕСТВА ПАРАМЕТРОВ В ТЕКТОВОМ ФАЙЛЕ ИЛИ СДЕЛАТЬ БАЗУ ДАННЫХ
    QVector<QString> *Param = new QVector<QString>[4];              //массив из 4 векторов для считывания данных, их может быть и больше вопрос к программе

    QVector<QString> TBC_Color= {                                                                   //варианты расцветки в зависимости от топлива
        "rgb(100,200,200)",
        "rgb(100,100,200)",
        "rgb(100,20,100)",
        "rgb(100,50,200)",
        "rgb(100,255,200)",
        "rgb(100,200,100)"};
    QVector<QString> Fuel_Name={                                                                //название топлива
        "Type_1",
        "Type_2",
        "Type_3",
        "Type_4",
        "Type_5",
        "Type_6"
    };
    QString Liner;              //для записи полной строки, так как считываем всю строку
    QString Str;                    //для записи нудного параметра
    QString Color_Nucler;
    while  (!File_Text.atEnd()){                                                                                                                                                    //считываем данные до конца файла
        Liner   = File_Text.readLine();                                                                                                                                             //построчно считываем данные
        for (int  i =0;  i <4 ; i++ ) {                                                                                                                                                         //смотря сколько параметров столько раз и считываем

            Param[i].append( Liner.left(    Liner.indexOf(  _Index_of_Separate    )   ));                                       //до знака табуляции копируем
                                                                                                                                                                                                                                        //добавляем в базу значение параметра



            Liner   = Liner.remove(    0,Liner.indexOf(    _Index_of_Separate  )+1);                                         //сжигаем из строки пройденный параметр

        }
    }
    File_Name->close();                                                                                                                                                                     //закрываем файл, так как считали всё что нужно
    QString Param_All;                                                                                                                                                                      //строка для считывания


   //Для нахождение данных для конкретной кнопки будем пробегать по всем кнопкам и по всем данным в файле

    //ТРЕБУЕТСЯ УЛУЧШИТЬ////
    for (int Iter_in_Button=0; Iter_in_Button < 163;Iter_in_Button++ ) {                                                         //пробегаем по всем кнопкам их 163
        for (int Iter_in_File = 0 ; Iter_in_File < 163 ;Iter_in_File++ ) {                                                            // пробегаем по всем данным по кнопкам в файле

            if ( Active_Zone[Iter_in_Button]->Nomer_TBC == Param[1][Iter_in_File].toInt()){                                                 //если совпадают то добавляем все параметры  на кнопку
                for (int Iter_Param = 0 ;Iter_Param < 4 ;Iter_Param++ ) {
                    Param_All.append(Param[Iter_Param][Iter_in_File]).append('\n');
                }

                Active_Zone[Iter_in_Button]->Set_Text(Param_All);                                                                   //конкретно добавление на конпку текста
                Param_All.clear();                                                                                                                                                                      //отчитска переменной для следующей кнопки

                for (        int Iter_Color=0      ;     Iter_Color   <    TBC_Color.count()    ;    Iter_Color++     )            //изменяем цвет кнопки в зависимости от типа топлива
                    if(Param[2][Iter_in_File].contains( Fuel_Name[Iter_Color]))
                        Active_Zone[Iter_in_Button]->Change_Color(TBC_Color[Iter_Color]);                                             //для этого для каждого обьекта кнопки вызвываем метод изменения цвета
            }
        }
    }
}
