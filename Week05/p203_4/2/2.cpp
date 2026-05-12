#include <iostream>
#include <vector>
using namespace std;

struct Move {
    char dir;
};

vector<Move> moves;

void replay() {
    cout << "=== REPLAY ===\n";
    for (auto m : moves) {
        cout << m.dir << " ";
    }
    cout << endl;
}

int main() {
    moves.push_back({'w'});
    moves.push_back({'a'});
    moves.push_back({'s'});
    moves.push_back({'d'});

    replay();

    return 0;
}