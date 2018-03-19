#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include<currebcy_pair.h>
#include <downloader.h>
#include <fstream>
#include <list>
#include<QList>
#include <iterator>
#include <iostream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //Currebcy_Pair *ReadFile();
    explicit Widget(QList *list, QWidget *parent = 0);
    //Currebcy_Pair s;
    ~Widget();

private slots:
    void readFile();
    void readFileNumber();
    void on_delete_2_clicked();

public slots:
    void AddNumber(QByteArray num);
 void AddNumberToList(Currebcy_Pair s);
void Prognoz();



 private:
    QList* list;
    Ui::Widget *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
   // Currebcy_Pair s();
};

#endif // WIDGET_H
