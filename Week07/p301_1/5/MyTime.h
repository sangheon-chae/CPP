#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
using namespace std;

class MyTime {
private:
    int hours;
    int minutes;
    int seconds;

public:
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();
};

#endif