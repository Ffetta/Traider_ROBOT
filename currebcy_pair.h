#ifndef CURREBCY_PAIR_H
#define CURREBCY_PAIR_H
#include<QString>


class Currebcy_Pair
{



public:
    Currebcy_Pair();
    Currebcy_Pair(QString _Name,   double Bay_Praice, double Sell_Praice, double Last_Traid):Name(_Name),
        bay_Praice(Bay_Praice),sell_Praice(Sell_Praice),last_Traid(Last_Traid){}
//    ~ Currebcy_Pair(){
//        delete[];
//    }

    QString Name;
    double bay_Praice;
    double sell_Praice;
    double last_Traid;
};

#endif // CURREBCY_PAIR_H
