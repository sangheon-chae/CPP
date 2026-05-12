#include <stdio.h>

struct MyTime {
    int hour;
    int minute;
    int second;
};

void addTime(MyTime t1, MyTime t2, MyTime& t3);

int main() {
    MyTime time1 = {2, 30, 45};
    MyTime time2 = {1, 45, 30};
    MyTime result = {0, 0, 0}; // 초기화

    addTime(time1, time2, result);
    printf("Result: %02d:%02d:%02d\n", result.hour, result.minute, result.second);

    return 0;
}


void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    int totaltime = (t1.hour * 3600 + t1.minute * 60 + t1.second) +
                    (t2.hour * 3600 + t2.minute * 60 + t2.second);

    t3.hour = (totaltime / 3600) % 24;
    t3.minute = (totaltime % 3600) / 60;
    t3.second = totaltime % 60;
}