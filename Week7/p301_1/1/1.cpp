#include <iostream>
#include <string.h>

using namespace std;

class MyTime {
private:
    int hours;
    int minutes;
    int seconds;

public:
   
    void convert(double duration) {
        int total = (int)duration;
        hours = total / 3600;
        minutes = (total % 3600) / 60;
        seconds = total % 60;
    }

    void print() {
    cout << (hours < 10 ? "0" : "");
    cout << hours << ":";
    cout << (minutes < 10 ? "0" : "");
    cout << minutes << ":";
    cout << (seconds < 10 ? "0" : "");
    cout << seconds << endl;
}

    MyTime add(MyTime t) {
        MyTime result;
        int total = seconds + t.seconds;
        result.seconds = total % 60;
        int carry = total / 60;

        total = minutes + t.minutes + carry;
        result.minutes = total % 60;
        carry = total / 60;

        total = hours + t.hours + carry;
        result.hours = total;

        return result;
    }

    void reset() {
        hours = minutes = seconds = 0;
    }
};


int main() {
    MyTime t1;
    MyTime t2;
    t1.print();
    
    return 0;
}