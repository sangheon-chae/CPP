#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> board = {1,2,3,4,5,6,7,8,0};
    int n = 3;

    for (int i = 0; i < n * n; i++) {
        if (board[i] == 0) cout << "   ";
        else cout << (char)('A' + board[i] - 1) << "  ";
        
        if ((i + 1) % n == 0) cout << endl;
    }

    return 0;
}