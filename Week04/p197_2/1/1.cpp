#include <stdio.h>


int reverse(int n) 
{
    int result = 0;
    while (n > 0)
    
    {
        int lastnum = n % 10;
        result = result * 10 + lastnum;
        n = n / 10;
    }
    
    return result;
}

int main()
{
    int n;
    int input;
    int output;
    
    printf("숫자를 입력하세요: ");
    scanf("%d", &input);
    
    output = reverse(input);

    printf("처음 숫자: %d\n", input);
    printf("뒤집힌 숫자: %d\n", output);
    return 0;
}
