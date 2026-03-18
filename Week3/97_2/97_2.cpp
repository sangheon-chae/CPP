// #include <iostream>

// int main()
// {
//    int n;

//    std ::cin >> n;
//    std ::cout << "10000미만의 정수를 입력하시오: ";

//    if(n >= 0 && n < 10000)
//    {
   
   
    
//     int a = n / 1000;
//     int b = (n % 1000) / 100;
//     int c = (n % 100) / 10;
//     int d = n % 10;

//     if(a != 0)
      
//         std::cout << a << "천 ";
      
//     if(b != 0)
      
//         std::cout << b << "백 ";   
           
//     if(c != 0)
      
//         std::cout << c << "십 ";
      
//     if(d != 0)
      
//         std::cout << d;
      
    
//     }
//     return 0;
    
// }


// #include <iostream>
// using namespace std;

// int main()
// {
//    int n;

//    cout << "입력 = "; 
//    cin >> n;

//    int millions = n / 10000;
//    if(millions > 0)
//       cout << millions << "만 ";          
//       n %= 10000;

//    int thousands = n / 1000;
//    if(thousands != 0)
//       cout << thousands << "천 ";          
//       n %= 1000;     

//    int hundreds = n / 100;
//    if(hundreds != 0)
//       cout << hundreds << "백 ";          
//       n %= 100;

//    int tens = n / 10;
//    if(tens != 0)
//       cout << tens << "십 ";         
//       n %= 10;


//    cout << "입력 = "; 
//    if(n != 0)
//       cout << n;
  


//    cout << "입력 = "; 
  

//    return 0;
// }  




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
         cout << "만 "; 
      } else {
         cout << millions << "만 ";   
      }      
   }
      n %= 10000;

   int thousands = n / 1000;
   if(thousands > 0){
      if(thousands == 1){
         cout << "천 ";          
      } else {
         cout << thousands << "천 ";         
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