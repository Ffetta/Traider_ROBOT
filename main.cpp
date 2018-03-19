#include "widget.h"
#include"graf.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graf v();
    QList *list = new QList;
    Widget w(list);
    w.show();
    v.show();

    return a.exec();
}
