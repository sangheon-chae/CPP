#include <iostream>
using namespace std;

int main()
{
   int n;

   cout << "입력 = "; 
   cin >> n;

   int millions = n / 10000;
   if(millions > 0){
      if(millions == 1){
          }
         }
      n %= 1000;

   int hundreds = n / 100;
   if(hundreds > 0){
      if(hundreds == 1){
         cout << "백 ";         
      } else {
         cout << hundreds << "백 ";         
          }
       }
      n %= 100;   

   int tens = n / 10;
   if(tens > 0){  
      if(tens == 1){
         cout << "십 ";         
      } else {
         cout << tens << "십 ";        
          }
      }
      n %= 10;

    if(n > 0){
       cout << n;
   }
   

   return 0;
} 