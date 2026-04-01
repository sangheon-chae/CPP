#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int score;
    cout << "점수 입력: ";
    cin >> score;

    ofstream out("rank.dat", ios::binary | ios::app);

    out.write((char*)&score, sizeof(int));

    out.close();

    cout << "랭킹 저장 완료\n";
    return 0;
}