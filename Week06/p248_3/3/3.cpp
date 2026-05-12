#include <stdio.h>

struct MyTime {
    int hour;
    int minute;
    int second;
};

void addTime(struct MyTime t1, struct MyTime t2, struct MyTime* pt);

int main() {
    struct MyTime  time1 = {2, 30, 45};
    struct MyTime  time2 = {1, 45, 30};
    struct MyTime  result;

    addTime(time1, time2, &result);
    printf("Result: %d:%d:%d\n", result.hour, result.minute, result.second);

    return 0;
}

void addTime(struct MyTime t1, struct MyTime t2, struct MyTime* pt) {
    int totaltime = (t1.hour * 3600 + t1.minute * 60 + t1.second) +
                       (t2.hour * 3600 + t2.minute * 60 + t2.second);

    pt->hour = (totaltime / 3600) % 24;
    pt->minute = (totaltime % 3600) / 60;
    pt->second = totaltime % 60;
}   

