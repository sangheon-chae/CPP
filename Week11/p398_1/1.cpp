#include <iostream>
#include <cstring>

using namespace std;

class Sample{
    char *name;

    static int count;

public:
    Sample(){
        name = NULL;
        count++;
    }
    Sample(const char *name){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    Sample(const Sample& src){
        if (src.name != NULL){
            this->name = new char[strlen(src.name) + 1];
            strcpy(this->name, src.name);
        } else { 
            this->name = NULL; 
        }
        count++;
   }

    ~Sample(){
        if (name != NULL){
            delete [] name;
        }
    }

    static void printCount(){
        cout << "Count : " << count << endl;
    }
};



int Sample :: count = 0;


int main(){

    Sample a("sample");
    Sample :: printCount();

    Sample b(a);
    Sample :: printCount();

    return 0;
}