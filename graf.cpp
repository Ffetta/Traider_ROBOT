#include "graf.h"
#include "ui_graf.h"

Graf::Graf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graf)
{
    ui->setupUi(this);
}

Graf::~Graf()
{
    delete ui;
}


////Сгенерируем данные
////Для этого создадим два массива точек:
////один для созранения x координат точек,
////а второй для y соответственно
//void Graf::Gafic(){
//double a = -1; //Начало интервала, где рисуем график по оси Ox
//double b =  1; //Конец интервала, где рисуем график по оси Ox
//double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
////int kolTochek=10;
//int N=10; //количество точек
//QVector<double> x(N), y(N); //Массивы координат точек

////Вычисляем наши данные
//int i=0;
//int kolSec=15;

//for (double X=a;  ; X+=kolSec)//Пробегаем по всем точкам
//{
//    x[i]=x;


//    y[i] = number;//Формула нашей функции
//    i++;
//}

//ui->widget->clearGraphs();//Если нужно, но очищаем все графики
////Добавляем один график в widget
//ui->widget->addGraph();
////Говорим, что отрисовать нужно график по нашим двум массивам x и y
//ui->widget->graph(0)->setData(x, y);

////Подписываем оси Ox и Oy
//ui->widget->xAxis->setLabel("x");
//ui->widget->yAxis->setLabel("y");

////Установим область, которая будет показываться на графике
//ui->widget->xAxis->setRange(a, b);//Для оси Ox

////Для показа границ по оси Oy сложнее, так как надо по правильному
////вычислить минимальное и максимальное значение в векторах
//double minY = y[0], maxY = y[0];
//for (int i=1; i<N; i++)
//{
//    if (y[i]<minY) minY = y[i];
//    if (y[i]>maxY) maxY = y[i];
//}
//ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

////И перерисуем график на нашем widget
//ui->widget->replot();
//}






//double *ReadFile(){

//    QFile file("C:/file.txt");
//    //QString str="";
//    if (!file.open(QIODevice::ReadOnly))
//            return NULL;



//   int search=100;
//    QByteArray str= file.read(search);

//    QString Name;
//    QByteArray BayPriseByte;
//    QByteArray SellPriseByte;
//    QByteArray LastTraid;
//    bool flag=1;
//    int control=0;
//    for(int i=0;i<search;i++){
//        if (str[i]=='}') break;
//        if (flag==0 && str[i]!=34){
//            switch (control) {
//            case 1:
//                Name+=str[i];

//                break;
//            case 5:
//                BayPriseByte+=str[i];
//                break;
//            case 9:
//                SellPriseByte+=str[i];
//                break;
//            case 13:
//                LastTraid+=str[i];
//                break;
//            default:
//                break;
//            }
//        }
//        if (str[i]==34){
//            flag=!flag;
//            control++;
//        }
//    }
//   double d1 = atof(BayPriseByte);
//    qDebug()<<BayPriseByte<<' '<<d1;//числа округляются до 2 знаков после точки
//   double d2 = atof(SellPriseByte);
//   double d3 = atof(LastTraid);
//  Widget c;
//   c.AddNumber(BayPriseByte);
//  Currebcy_Pair *now= new Currebcy_Pair(Name, d1, d2,d3);

//  return now;

//}
