#ifndef GRAF_H
#define GRAF_H

#include <QWidget>

namespace Ui {
class Graf;
}

class Graf : public QWidget
{
    Q_OBJECT

public:
    explicit Graf(QWidget *parent = 0);
    ~Graf();

private:
    Ui::Graf *ui;
public slots:
   // void Gafic();

};

#endif // GRAF_H
