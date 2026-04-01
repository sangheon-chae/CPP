#include <iostream>
#include <iomanip> // 출력을 예쁘게 맞추기 위한 헤더


using namespace std;

void checkMap( int map[5][5]){
   
     cout << "---Row check ---" << endl;
    for (int i = 0; i < 5; i++){
        bool allSame = true;
        for (int j = 1; j < 5; j++){
            if (map[i][j] != map[i][0]){
                allSame = false;
                break;
            }
        }
        if (allSame){
            cout << "Row " << i << " is all " << map[i][0] << endl;
        }
    }

    cout << "---Column check ---" << endl;
    for (int j = 0; j < 5; j++){
        bool allSame = true;
        for (int i = 1; i < 5; i++){
            if (map[i][j] != map[0][j]){
                allSame = false;
                break;
            }
        }
        if (allSame){
            cout << "Column " << j << " is all " << map[0][j] << endl;
        }
    }   

    cout << "\n---Diagonal check ---" << endl; // 대각선 체크

    bool diag1Same = true;
    for (int i = 1; i < 5; i++){
        if (map[i][i] != map[0][0]){
            diag1Same = false;
            break;
        }
    }
    if (diag1Same){
        cout << "Main Diagonal is all " << map[0][0] << endl;
    }


    bool diag2Same = true;
    for (int i = 1; i < 5; i++){
        if (map[i][4 - i] != map[0][4]){
            diag2Same = false;
            break;
        }
    }
    if (diag2Same){
        cout << "Main Diagonal 2 is all " << map[0][4] << endl;
    }
       cout << "-------------------" << endl;
}

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
     
    cout << "Original checkerboard map:" << endl;
    printMap( map );
    cout << "Checking for uniform rows, columns, and diagonals..." << endl;
    checkMap( map );

    int testMap[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    cout << "\nTesting with all-zeromap:" << endl;
    printMap( testMap );
    cout << "Checking for uniform rows, columns, and diagonals" << endl;
    checkMap( testMap );

    int testMap2[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},    
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1}
    };
    cout << "\nTesting with diagonal-one map:" << endl;
    printMap( testMap2 );
    cout << "Checking for uniform rows, columns, and diagonals" << endl;
    checkMap( testMap2 );


    return 0;
}