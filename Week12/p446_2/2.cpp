#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Monster {
protected:
    string name;
    int x, y;
public:
    Monster(string n, int x = 0, int y = 0) : name(n), x(x), y(y) {}
    virtual ~Monster() {}
    virtual void move() = 0; 
    virtual void print() {
        cout << name << " 위치: (" << x << ", " << y << ")" << endl;
    }
};

class Jiangshi : public Monster {
protected:
    bool bVertical; 
public:
    Jiangshi(string n, int x = 0, int y = 0, bool v = true) : Monster(n, x, y), bVertical(v) {}
    void move() override {
        int dist = (rand() % 2 == 0) ? 1 : -1; 
        if (bVertical) y += dist;
        else x += dist;
    }
};




class Smombi : public Monster {
public:
    Smombi(string n, int x = 0, int y = 0) : Monster(n, x, y) {}
    
    void move() override {
        
        x += (rand() % 2 == 0) ? 1 : -1;
        y += (rand() % 2 == 0) ? 1 : -1;
    }
};


class Siangshi : public Jiangshi {
private:
    int moveCount; 
public:
    Siangshi(string n, int x = 0, int y = 0, bool v = true) : Jiangshi(n, x, y, v), moveCount(0) {}
    
    void move() override {
        moveCount++;
        
        if (moveCount % 3 == 0) {
            bVertical = !bVertical; 
        }
       
        Jiangshi::move();
    }
};


class Ghost : public Monster {
public:
    Ghost(string n, int x = 0, int y = 0) : Monster(n, x, y) {}
    
    void move() override {
        
        x += (rand() % 5 - 2); 
        y += (rand() % 5 - 2);
    }
};


int main() {
   
    srand((unsigned int)time(NULL));

    
    Monster* world[3];
    world[0] = new Smombi("스몸비", 10, 10);
    world[1] = new Siangshi("수퍼강시(샹시)", 10, 10, true);
    world[2] = new Ghost("순간이동유령", 10, 10);

    cout << "--- 초기 몬스터 위치 ---" << endl;
    for (int i = 0; i < 3; i++) {
        world[i]->print();
    }
    cout << endl;

 
    for (int turn = 1; turn <= 5; turn++) {
        cout << "[ " << turn << " 턴 이동 결과 ]" << endl;
        for (int i = 0; i < 3; i++) {
            world[i]->move(); 
            world[i]->print();
        }
        cout << endl;
    }

   
    for (int i = 0; i < 3; i++) {
        delete world[i];
    }

    return 0;
}
