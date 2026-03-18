#include <iostream>

int  main() // 1번
{
for(int i = 1; i <= 5; ++i)

   {
    for(int j = 1; j <= i; ++j)
    {
        std:: cout << j;
    }
    std::cout << "\n";
   }
}


#include <iostream>

int  main() // 2번
{
for(int i = 5; i >= 1; --i)

   {
    for(int j = i; j >= 1; --j)
    {
        std:: cout << j;
    }
    std::cout << "\n";

   }
  return 0;
 }


 #include <iostream>

int  main() // 3번
{
for(int i = 1; i <= 5; ++i)

   {
    for(int k = 1; k <= 5-i; ++k)
    {
        std:: cout << "  ";
    }
    for(int j = i; j >= 1; --j)
    {
        std:: cout << j << " ";
    }
    std::cout << "\n";

}
  return 0;
 }


 #include <iostream>

int  main() // 4번
{
for(int i = 1; i <= 5; ++i)

   {
    for(int k = 1; k <= 5 - i; ++k)
    {
        std:: cout << "  ";
    }
    for(int j = i; j >= 1; --j)
    {
        std:: cout << j << " ";
    }
    for(int j = 2; j <= i; ++j)
    {
    std:: cout << j << " ";
    }
    std::cout << "\n";

}
  return 0;
 }