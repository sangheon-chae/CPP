#include <iomanip> // 출력을 예쁘게 맞추기 위한 헤더
#include <iostream>

using namespace std;


void printMap( int map[5][5] ){
    cout << "---Checker Board---" << endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
    if( map[i][j] == 0 ){
        cout << "0 ";
    } else {
        cout << "1 ";
    }
        }
         cout << endl;
    }
    cout << "-------------------" << endl;
}

int main()
{
    int map[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    printMap( map );

    return 0;
}