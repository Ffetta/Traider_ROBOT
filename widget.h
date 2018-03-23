#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include<currebcy_pair.h>
#include <downloader.h>
#include <fstream>
#include <list>
#include <QList>
#include <iterator>
#include <iostream>
#include <graf.h>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QList<Currebcy_Pair> *list = nullptr, QWidget *parent = 0);
    ~Widget();
     //boost::signal<void()> OnPressed; //Сигнал
    bool up_or_down();
    signals:
      void onReady();

private slots:
    void readFile();
    void readFileNumber();
    void on_delete_2_clicked();

public slots:
    void AddNumber(QByteArray num);
    void AddNumberToList(Currebcy_Pair s);
    void Prognoz();




 private:
    QList<Currebcy_Pair>* list;
    Ui::Widget *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
    Graf *graf;
   // Currebcy_Pair s();
};

#endif // WIDGET_H
