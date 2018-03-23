#include "widget.h"
#include "ui_widget.h"
#include <fstream>
QList <Currebcy_Pair> spisok;
Widget::Widget(QList<Currebcy_Pair> *_list, QWidget *parent) :
    list(_list),
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    downloader = new Downloader();
    graf =new Graf(list);
    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    connect(downloader, &Downloader::onReady, this, &Widget::readFile);
    connect(downloader, &Downloader::onReady, this, &Widget::readFileNumber);
    connect(this,&Widget::onReady , graf, &Graf::on_pushButton_clicked );
    //signal(ref)

}

Widget::~Widget()
{
    delete ui;
}


void Widget::AddNumber(QByteArray num){
    num+=' ';
    QFile *file = new QFile("C:/number.txt");
    if(file->open(QFile::Append))
    file->write(num);
    file->close();
}


void Widget::AddNumberToList(Currebcy_Pair s){
   // List <Currebcy_Pair> spisok;
   if(spisok.size()>10){
       spisok.pop_front();
   }
   spisok.push_back(s);
}


Currebcy_Pair  *ReadFile(){
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
   qDebug()<<BayPriseByte<<' '<<d1;
   double d2 = atof(SellPriseByte);
   double d3 = atof(LastTraid);
  Widget c;
   c.AddNumber(BayPriseByte);
  Currebcy_Pair *now= new Currebcy_Pair(Name, d1, d2,d3,clock());
  c.AddNumberToList(*now);
  return now;

}

void wait ( int seconds ) // доступно для int. Если сделать double seconds(будет работать, но есть варнинг)
{
  clock_t endwait;
  //qDebug()<<endwait<<'e';
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

bool Widget::up_or_down(){
    Currebcy_Pair *n= nullptr;
    for(int i=0; i<11;i++){
        if (list->at(i).getTime()==clock()-60*CLOCKS_PER_SEC){
            n=list->at(i);
        }
        if(n!=nullptr){//Если цены равны то считается что мы выйграли
            if (n->getBay_Praice()<=list->back().getBay_Praice()){//1 когда вверх , 0 когда вниз
                return 1;
            }
            if(n->getBay_Praice()>=list->back().getBay_Praice()){
                return 0;
            }
        }
        else
        {
            qDebug<<"error";
            return 0;
        }
    }
}

void Widget::Prognoz(){
    bool lastRate= up_or_down();   //Вместо этого должен быть алгоритм определения

    if (list->size()>11){
        list->removeAt(0);
    }
    list->push_back(*ReadFile());


    Currebcy_Pair d=*ReadFile();
    double First = d.bay_Praice;

    emit onReady();
 //   Graf c;
//    connect(this, , downloader, &Downloader::getData);
   //c.Gafic();
    //on_pushButton_clicked();   // wait(1);
   // Prognoz();

  //  Currebcy_Pair *v=ReadFile();// как здесь не создавть доп объекты
    //double Second=ReadFile()->bay_Praice;

   // qDebug()<< "     " <<First<<endl<<Second;

}
void Widget::readFile()
{
    QFile file("C:/file.txt");

     if (list->size()==0){
         for(int i=0;i<10;i++){
           list->push_back(*ReadFile());
        }
    }
        Prognoz();
    if (!file.open(QIODevice::ReadOnly))
            return;
    ui->textEdit->setText(file.readAll());
}


void Widget::readFileNumber()
{
    QFile file("C:/number.txt");
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
    }
}
