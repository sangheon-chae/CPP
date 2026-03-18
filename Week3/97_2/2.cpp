#include <iostream>
using namespace std;

int main()
{
   int n;

   cout << "입력 = "; 
   cin >> n;

   int millions = n / 10000;
   if(millions > 0)
      cout << millions << "만 ";          
      n %= 10000;

   int thousands = n / 1000;
   if(thousands != 0)
      cout << thousands << "천 ";          
      n %= 1000;     

   int hundreds = n / 100;
   if(hundreds != 0)
      cout << hundreds << "백 ";          
      n %= 100;

   int tens = n / 10;
   if(tens != 0)
      cout << tens << "십 ";         
      n %= 10;


   cout << "입력 = "; 
   if(n != 0)
      cout << n;
  


   cout << "입력 = "; 
  

   return 0;
}  
