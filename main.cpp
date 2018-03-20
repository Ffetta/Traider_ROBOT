#include "widget.h"
#include"graf.h"
#include <QApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<Currebcy_Pair> *list = new QList<Currebcy_Pair>;
    Widget w(list);
    Graf v(list);
    w.show();
    v.show();

    return a.exec();
}
