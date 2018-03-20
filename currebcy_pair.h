#ifndef CURREBCY_PAIR_H
#define CURREBCY_PAIR_H
#include<QString>
#include<QList>


class Currebcy_Pair
{



public:
    Currebcy_Pair();
    Currebcy_Pair(QString _Name,   double Bay_Praice, double Sell_Praice, double Last_Traid,time_t Time):Name(_Name),
        bay_Praice(Bay_Praice),sell_Praice(Sell_Praice),last_Traid(Last_Traid),time(Time){}
//    ~ Currebcy_Pair(){
//        delete[];
//    }
    time_t time;
    QString Name;
    double bay_Praice;
    double sell_Praice;
    double last_Traid;
    double getBay_Praice() const;
    void setBay_Praice(double value);
    time_t getTime() const;
    void setTime(const time_t &value);
};

//class Spisok{
//   QList spicok;
//}

#endif // CURREBCY_PAIR_H
