#include <iostream>  
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int bullets, players, n, trigger;
    cout << "탄창 수(n): ";
    cin >> n;

    cout << "플레이어 수: ";
    cin >> players; 

    cout << "총알 수: ";
    cin >> bullets;

    srand(time(0));

    int count = 0;

    while(bullets > 0)
    {
        trigger = rand() % n;

        cout << (count % players) + 1 << "번 플레이어의 차례입니다.\n";

    if(trigger == 0)
    {
        cout << "맞음!\n";
        bullets--;
        
    }
    else
    {
        cout << "맞지 않음!\n";
    }
    count++;
    }
    cout << "게임 종료!";

    return 0;
}


