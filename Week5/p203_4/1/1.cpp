#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<int>& board, int n) {
    for (int i = 0; i < n * n; i++) {
        if (board[i] == 0) cout << "   ";
        else cout << board[i] << "  ";
        if ((i + 1) % n == 0) cout << endl;
    }
}

int main() {
    int n;
    cout << "퍼즐 크기 선택 (3 / 4 / 5): ";
    cin >> n;

    vector<int> board(n * n);

    for (int i = 0; i < n * n - 1; i++) {
        board[i] = i + 1;
    }
    board[n * n - 1] = 0;

    printBoard(board, n);

    return 0;
}