#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<int> board = {1,2,3,4,5,6,7,8,0};
    int n = 3;
    int moveCount = 10;

    ofstream out("save.dat", ios::binary);

    int size = board.size();

    out.write((char*)&n, sizeof(int));
    out.write((char*)&size, sizeof(int));
    out.write((char*)board.data(), sizeof(int) * size);
    out.write((char*)&moveCount, sizeof(int));

    out.close();

    cout << "저장 완료\n";
    return 0;
}