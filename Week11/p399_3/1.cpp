#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Monster {
private:
    string name;
    char icon;
    int x, y;
    int nEnergy;          
    static int nMonsters; 

public:
    
    Monster(string n = "Monster", char i = '@', int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nEnergy(100) { 
        nMonsters++; 
    }

    
    virtual ~Monster() {
        nMonsters--; 
    }

    
    int getEnergy() const { return nEnergy; }
    
    void decreaseEnergy(int amount) { nEnergy -= amount; }

    void print() const {
        cout << name << icon << ": E:" << nEnergy << " ";
    }

    
    static void printCount() {
        cout << "전체 몬스터의 수: [" << nMonsters << "]" << endl;
    }
};
int Monster::nMonsters = 0;


class MonsterWorld {
private:
    Monster* pMon[100]; 
    int nMon;           

public:
    MonsterWorld() : nMon(0) {}

   
    void addMonster(Monster* m) {
        if (nMon < 100) {
            pMon[nMon++] = m;
        }
    }

  
    void checkStarvation() {
        for (int i = 0; i < nMon; ) {
            if (pMon[i]->getEnergy() <= 0) {
                cout << "Monster 하나가 굶어죽습니다" << endl;
                
                delete pMon[i]; 
                delete pMon[i]; 

                
                if (nMon > 1) {
                    pMon[i] = pMon[nMon - 1];
                }
                nMon--;
                
              
            } else {
                i++;
            }
        }
    }

    void display() {
        for (int i = 0; i < nMon; i++) {
            pMon[i]->print();
        }
        cout << endl;
        Monster::printCount(); 
    }
};

int main() {
    MonsterWorld mw;

    
    mw.addMonster(new Monster("고스트", 'G', 1, 1));
    mw.addMonster(new Monster("도깨비", 'D', 2, 2));
    
    cout << "--- 초기 상태 ---" << endl;
    mw.display();

   
    
    cout << "\n--- 굶주림 체크 후 ---" << endl;
 
    mw.checkStarvation(); 
    mw.display();

    return 0;
}