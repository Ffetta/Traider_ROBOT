#ifndef GRAF_H
#define GRAF_H

#include <QWidget>
#include "currebcy_pair.h"
#include <iostream>
#include <list>
#include <iterator>

namespace Ui {
class Graf;
}

class Graf : public QWidget
{
    Q_OBJECT

public:
    explicit Graf(QList<Currebcy_Pair> *list = nullptr, QWidget *parent = 0);
    ~Graf();
    void Gafic();

private:
     QList<Currebcy_Pair>* list;
    Ui::Graf *ui;
public slots:
  //  void Gafic();

//private slots:
    void on_pushButton_clicked();
};

#endif // GRAF_H
