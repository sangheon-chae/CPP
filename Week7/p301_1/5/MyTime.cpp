#include <iostream>
#include <iomanip> 
#include "MyTime.h"

using namespace std;


void MyTime::convert(double duration) {
  
    hour = (int)(duration / 3600);
    minute = (int)((duration - hour * 3600) / 60);
    second = (int)(duration - hour * 3600 - minute * 60);
    millisecond = (int)((duration - (int)duration) * 1000);
}

void MyTime::reset() {
    hour = 0;
    minute = 0;
    second = 0;
    millisecond = 0;
}

void MyTime::print() {
   
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << ":"
         << setw(3) << millisecond << endl;
}

MyTime MyTime::add(MyTime t) {
   
    MyTime result;
    
    return result;
}

void MyTime::reset() {
    hour = minute = second = millisecond = 0;
}

void MyTime::read() {
   
    cout << "시간(시 분 초 밀리초)을 입력하세요: ";
    cin >> hour >> minute >> second >> millisecond;
}