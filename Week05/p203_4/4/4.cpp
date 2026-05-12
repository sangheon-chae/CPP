#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<int> board;
    int n, size, moveCount;

    ifstream in("save.dat", ios::binary);

    if (!in) {
        cout << "저장 파일 없음\n";
        return 0;
    }

    in.read((char*)&n, sizeof(int));
    in.read((char*)&size, sizeof(int));

    board.resize(size);
    in.read((char*)board.data(), sizeof(int) * size);

    in.read((char*)&moveCount, sizeof(int));
    in.close();

    cout << "불러오기 완료\n";

    for (int i = 0; i < size; i++) {
        cout << board[i] << " ";
        if ((i + 1) % n == 0) cout << endl;
    }

    return 0;
}