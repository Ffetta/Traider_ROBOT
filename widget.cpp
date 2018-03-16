#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    downloader = new Downloader();


    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);

    connect(downloader, &Downloader::onReady, this, &Widget::readFile);

}

Widget::~Widget()
{
    delete ui;
}


Currebcy_Pair *ReadFile(){

    QFile file("C:/file.txt");
    //QString str="";
    if (!file.open(QIODevice::ReadOnly))
            return NULL;



   int search=100;
    QByteArray str = file.read(search);
    QString Name;
    QByteArray BayPriseByte;
    QByteArray SellPriseByte;
    QByteArray LastTraid;
    bool flag=1;
    int control=0;
    for(int i=0;i<search;i++){
        if (str[i]=='}') break;
        if (flag==0 && str[i]!=34){
            switch (control) {
            case 1:
                Name+=str[i];

                break;
            case 5:
                BayPriseByte+=str[i];
                break;
            case 9:
                SellPriseByte+=str[i];
                break;
            case 13:
                LastTraid+=str[i];
                break;
            default:
                break;
            }
        }
        if (str[i]==34){
            flag=!flag;
            control++;
        }
    }
   double d1 = atof(BayPriseByte);
    qDebug()<<BayPriseByte<<' '<<d1;//числа округляются до 2 знаков после точки
   double d2 = atof(SellPriseByte);
   double d3 = atof(LastTraid);
  Currebcy_Pair *now= new Currebcy_Pair(Name, d1, d2,d3);

  return now;

}

void wait ( int seconds ) // доступно для int. Если сделать double seconds(будет работать, но есть варнинг)
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}



void Prognoz(){
    bool Up_or_donw=rand();//Вместо этого должен быть алгоритм определения
    Currebcy_Pair d=*ReadFile();
    double First = d.bay_Praice;
    //wait(10);
    Currebcy_Pair v=*ReadFile();// как здесь не создавть доп объекты
    double Second=v.bay_Praice;
    qDebug()<< "     " <<First<<endl<<Second;

}
void Widget::readFile()
{
    QFile file("C:/file.txt");
    Prognoz();
    if (!file.open(QIODevice::ReadOnly))
            return;

    ui->textEdit->setText(file.readAll());
}
