#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include<currebcy_pair.h>
#include <downloader.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    //Currebcy_Pair s;
    ~Widget();

private slots:
    void readFile();





 private:
    Ui::Widget *ui;
    Downloader *downloader; // Объявляем объект класса для скачивания данных по http
    Currebcy_Pair s();
};

#endif // WIDGET_H
