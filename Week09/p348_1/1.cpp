#include <iostream>

using namespace std;

class MyTime {
    int hour, minute, second, msec;
public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) : hour(h), minute(m), second(s), msec(ms) { }


void printTime(){
    std::cout << hour << ":" << minute << ":" << second << "." << msec << std::endl;
   }
};
int main() {
   
    MyTime t1; 
    t1.printTime();

   
    MyTime t2(10, 30, 25, 500); 
    t2.printTime();

    return 0;
}