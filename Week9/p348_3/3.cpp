#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<string>
#include <unistd.h> // usleep 함수 사용을 위한 헤더

using namespace std;

class Monster {
    string name;
    int x, y;
    int nEnergy; // (1) 에너지 속성 추가

public:
   
    Monster(string n = "몬스터", int x = 0, int y = 0)
        : name(n), x(x), y(y), nEnergy(100) { }

    ~Monster() {
        
    }

    void draw(char canvas[20][40]) { // 캔버스 크기 수정
        canvas[y][x] = 'M';
    }

    //  함수: 아이템 유무에 따라 에너지 변화
    void eat(bool bItemFound) {
        if (bItemFound) nEnergy += 8;
        else            nEnergy -= 1;
        if (nEnergy < 0) nEnergy = 0;
    }

    void move(int xMax, int yMax) {
        int steps = rand() % 8;
        switch (steps) {
        case 0: y--; break; case 1: y++; break;
        case 2: x--; break; case 3: x++; break;
        case 4: x--; y--; break; case 5: x++; y--; break;
        case 6: x--; y++; break; case 7: x++; y++; break;
        }
        
        if (x < 0) x = 0; if (x >= xMax) x = xMax - 1;
        if (y < 0) y = 0; if (y >= yMax) y = yMax - 1;
    }

    
    void print() {
        printf(" %s:%d", name.c_str(), nEnergy);
    }

    int getX() { return x; }
    int getY() { return y; }
};


class Canvas {
    char map[20][40];
public:
    Canvas() { clear(); }
    void clear() {
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 40; j++) map[i][j] = '.';
    }
    void draw(int x, int y, char symbol) { map[y][x] = symbol; }
    void print() {
        system("cls"); 
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) printf("%c", map[i][j]);
            printf("\n");
        }
    }
};


class MonsterWorld {
    int width, height;
    int nMon, nItem;
    Monster* monsters[10]; // 최대 몬스터 수
    int itemX[30], itemY[30]; // 아이템 위치
    Canvas canvas;

public:
    MonsterWorld(int w, int h) : width(w), height(h), nMon(0), nItem(0) {
        srand((unsigned int)time(NULL));
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++) delete monsters[i];
    }

    void addMonster(string name) {
        if (nMon < 10) {
            monsters[nMon++] = new Monster(name, rand() % width, rand() % height);
        }
    }

    void setItem(int n) {
        nItem = n;
        for (int i = 0; i < nItem; i++) {
            itemX[i] = rand() % width;
            itemY[i] = rand() % height;
        }
    }

    // 아이템 획득 여부 체크 로직
    bool checkItem(int x, int y) {
        for (int i = 0; i < nItem; i++) {
            if (itemX[i] == x && itemY[i] == y) {
                itemX[i] = -1; // 아이템 제거
                return true;
            }
        }
        return false;
    }

    void play() {
        while (nItem > 0) {
           
            for (int i = 0; i < nMon; i++) {
                monsters[i]->move(width, height);
                bool found = checkItem(monsters[i]->getX(), monsters[i]->getY());
                monsters[i]->eat(found);
            }

            
            int count = 0;
            for (int i = 0; i < nItem; i++) if (itemX[i] != -1) count++;
            nItem = count;

           
            render();
            usleep(200000);
            
        }
    }

    void render() {
        canvas.clear();
        
        for (int i = 0; i < 30; i++) { 
            if (itemX[i] != -1) canvas.draw(itemX[i], itemY[i], 'I');
        }
      
        for (int i = 0; i < nMon; i++) {
            canvas.draw(monsters[i]->getX(), monsters[i]->getY(), 'M');
        }
        canvas.print();

        
        for (int i = 0; i < nMon; i++) {
            monsters[i]->print();
        }
        printf("\n");
    }
};
    
int main() {
    
    MonsterWorld game(40, 20);

    game.addMonster("도깨비");
    game.addMonster("별그대");
    game.addMonster("고스트");
    game.setItem(20);
    game.play();

    printf("게임이 종료되었습니다.\n");
    return 0;
}