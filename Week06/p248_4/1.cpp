#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


static int MineMapMask[40][80];  
static int MineMapLabel[40][80]; 

int R = 40;
int C = 80;
// 전역 변수로 크기 고정

void init(int total) {
    srand((unsigned int)time(NULL)); // 함수들

    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    } // 1.맵 초기화

    // 2. 
    int count = 0;
    while (count < total) {
        int r = rand() % R;
        int c = rand() % C;
        if (MineMapLabel[r][c] != -1) {
            MineMapLabel[r][c] = -1;
            count++;
        }
    }// 2. 랜덤으로 지뢰 매설

    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MineMapLabel[i][j] == -1) continue;
            
            int mine_cnt = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int ni = i + dr;
                    int nj = j + dc;
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        if (MineMapLabel[ni][nj] == -1) mine_cnt++;
                    }
                }
            }
            MineMapLabel[i][j] = mine_cnt;
        }
    }
}// 3. 숫자 계산 (주변 8칸 지뢰 세기)

void draw(bool reveal) {
    system("cls"); 
    cout << "   ";
    for (int j = 0; j < C; j++) cout << j % 10; // 열 번호 (일의 자리만)
    cout << endl;

    for (int i = 0; i < R; i++) {
        if (i < 10) cout << " " << i << "|"; // 행 번호 맞춤
        else cout << i << "|";

        for (int j = 0; j < C; j++) {
            if (!reveal && MineMapMask[i][j] == 0) cout << "#";      // 가려진 곳
            else if (!reveal && MineMapMask[i][j] == 2) cout << "P"; // 깃발
            else {
                if (MineMapLabel[i][j] == -1) cout << "*";          // 지뢰
                else if (MineMapLabel[i][j] == 0) cout << ".";      // 빈 땅
                else cout << MineMapLabel[i][j];                    // 숫자
            }
        }
        cout << "|" << endl;
    }
}


void dig(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (MineMapMask[r][c] == 1) return;

    MineMapMask[r][c] = 1;
    
    // 빈 땅 클릭 시 주변 자동 확장
    
    if (MineMapLabel[r][c] == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                dig(r + i, c + j);
            }
        }
    }
}

int checkDone(int total) {
    int closed = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (MineMapMask[i][j] != 1) closed++;
        }
    }
    if (closed == total) return 1; // 승리
    return 0; // 진행중
}

void PlayMineSweeper(int total) {
    int x, y, action, status = 0;
    init(total);

    while (status == 0) {
        draw(false);
        cout << "\n[입력] 행 열 행동(0:파기, 1:깃발): ";
        cin >> x >> y >> action;

        if (x < 0 || x >= R || y < 0 || y >= C) continue;

        if (action == 1) {
            if (MineMapMask[x][y] == 0) MineMapMask[x][y] = 2;
            else if (MineMapMask[x][y] == 2) MineMapMask[x][y] = 0;
        } else {
            if (MineMapLabel[x][y] == -1) {
                status = -1; // 지뢰 밟음
            } else {
                dig(x, y);
            }
        }

        if (status != -1) status = checkDone(total);
    }

    draw(true);
    if (status == -1) cout << "\nGame Over! 지뢰를 밟았습니다!" << endl;
    else cout << "\nCongratulations! 성공입니다!" << endl;
}

int main() {
    int total;
    cout << " <지뢰찾기 과제> " << endl;
    cout << " 매설할 지뢰 개수: ";
    cin >> total;

    PlayMineSweeper(total);

    return 0;
}