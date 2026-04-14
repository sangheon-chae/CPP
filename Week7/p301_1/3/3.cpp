#include <iostream>
#include <iomanip>

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
    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;
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
    MyTime t1, t2, t3;

    t1.convert(3661);  // 01:01:01
    t2.convert(59);    // 00:00:59

    t3 = t1.add(t2);

    cout << "t1: "; t1.print();
    cout << "t2: "; t2.print();
    cout << "t1 + t2: "; t3.print();

    return 0;
}