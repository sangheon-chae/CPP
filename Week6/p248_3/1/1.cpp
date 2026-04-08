#include <stdio.h>
#include <time.h>

struct MyTime {
    int hour;
    int minute;
    int second;
};

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime result;
    int totaltime = (t1.hour * 3600 + t1.minute * 60 + t1.second) +
                       (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    result.hour = (totaltime / 3600) % 24; 
    result.minute = (totaltime % 3600) / 60;
    result.second = totaltime % 60;
    
    return result;
}
int main() {
    MyTime time1 = {2, 30, 45};
    MyTime time2 = {1, 45, 30};

    MyTime result = addTime(time1, time2);
    printf("Result: %d:%d:%d\n", result.hour, result.minute, result.second);

    return 0;
}