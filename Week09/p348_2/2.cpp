#include <iostream>
#include <cstdio>

class MyTime {
    int hour, min, sec, msec;

public:
    
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), msec(ms) {}

    
    MyTime(double duration) {
        hour = (int)(duration / 3600);          
        duration -= hour * 3600;
        
        min = (int)(duration / 60);             
        duration -= min * 60;
        
        sec = (int)duration;                    
        
        
        msec = (int)((duration - sec) * 1000 + 0.5); 
    }
    void print() {

        printf("%02d:%02d:%02d.%03d\n", hour, min, sec, msec);
    }
};

int main() {
    MyTime t1(1, 30, 45, 500); 
    t1.print();

    MyTime t2(3661.5);         
    t2.print();

    return 0;
}