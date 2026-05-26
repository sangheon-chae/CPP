#include <iostream>

using namespace std;

class Sample1{
    public:
         Sample1(){}
    virtual void play(){cout << "1번 sample" << endl;}
         
};

class Sample2{
    public:
         Sample2(){}
         virtual void play(){cout << "2번 sample" << endl;}
};

class Sample3{
    public:
         Sample3(){}
         virtual void play(){cout << "3번 sample" << endl;}
};

class Sample4 : public Sample1  
{
    public:
            Sample4(){}
            virtual void play(){cout << "4번 sample" << endl;}
};

int main(){
    Sample2* arr[4];

    Sample1* a = new Sample1();
    Sample2* b = new Sample2();
    Sample3* c = new Sample3();
    Sample4* d = new Sample4();
    
    arr[0] = a;
    arr[1] = (Sample1*)b;
    arr[2] = (Sample1*)c;
    arr[3] = (Sample1*)d;

    for(int i = 0; i < 4; i++){
        arr[i]->play();
    }
    return 0;