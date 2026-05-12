#include <iostream>

int main()
{
   int n;

   std ::cin >> n;
   std ::cout << "10000미만의 정수를 입력하시오: ";

   if(n >= 0 && n < 10000)
   {
   
   
    
    int a = n / 1000;
    int b = (n % 1000) / 100;
    int c = (n % 100) / 10;
    int d = n % 10;

    if(a != 0)
      
        std::cout << a << "천 ";
      
    if(b != 0)
      
        std::cout << b << "백 ";   
           
    if(c != 0)
      
        std::cout << c << "십 ";
      
    if(d != 0)
      
        std::cout << d;
      
    
    }
    return 0;
    
}







