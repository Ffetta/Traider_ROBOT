#include "widget.h"
#include "ui_widget.h"
#include <fstream>
QList <Currebcy_Pair> spisok;
Widget::Widget(QList* _list, QWidget *parent) :
    list(_list),
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    downloader = new Downloader();


    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    connect(downloader, &Downloader::onReady, this, &Widget::readFile);

    connect(downloader, &Downloader::onReady, this, &Widget::readFileNumber);




}

Widget::~Widget()
{
    delete ui;
}


void Widget::AddNumber(QByteArray num){
    num+=' ';
    //list;
    QFile *file = new QFile("C:/number.txt");
    if(file->open(QFile::Append))

   // QByteArray CharNum=(QByteArray)num;

    file->write(num);

 //   file->write();

    file->close();

}


void Widget::AddNumberToList(Currebcy_Pair s){

   // List <Currebcy_Pair> spisok;

   if(spisok.size()>10){
       spisok.pop_front();
   }

   spisok.push_back(s);


}


Currebcy_Pair *ReadFile(){

    QFile file("C:/file.txt");
    //QString str="";
    if (!file.open(QIODevice::ReadOnly))
            return NULL;




   int search=100;
    QByteArray str= file.read(search);

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
   double d1 = BayPriseByte.toDouble();
    qDebug()<<BayPriseByte<<' '<<d1;//числа округляются до 2 знаков после точки
   double d2 = atof(SellPriseByte);
   double d3 = atof(LastTraid);
  Widget c;
   c.AddNumber(BayPriseByte);

  Currebcy_Pair *now= new Currebcy_Pair(Name, d1, d2,d3);
  c.AddNumberToList(*now);

  return now;

}

void wait ( int seconds ) // доступно для int. Если сделать double seconds(будет работать, но есть варнинг)
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


void Widget::Prognoz(){
    bool Up_or_donw=rand();//Вместо этого должен быть алгоритм определения

    Currebcy_Pair d=*ReadFile();
    double First = d.bay_Praice;
    //wait(10);
  //  Currebcy_Pair *v=ReadFile();// как здесь не создавть доп объекты
    double Second=ReadFile()->bay_Praice;

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
void Widget::readFileNumber()
{
    QFile file("C:/number.txt");
   // Prognoz();
    if (!file.open(QIODevice::ReadOnly))
            return;

    ui->textEdit->setText(file.readAll());
}





void Widget::on_delete_2_clicked()
{
    QFile *file = new QFile("C:/number.txt");

    if(file->open(QFile::WriteOnly)){
        file->write("");
        file->close();
  //  qDebug() << "Downloading is completed";
   // emit onReady();
}
}
