#include <iostream>  
using namespace std;

int main()
{
   int n;
    double pi = 0, sign = 1;

   cout << "입력 = "; 
   cin >> n;

   for(int i = 0; i <= n; i++){
      pi += sign / ( 2 * i + 1 );
      sign = -sign;     
    }
    
    cout << "pi = " << pi * 4 << "\n";
  
   

   return 0;   
}