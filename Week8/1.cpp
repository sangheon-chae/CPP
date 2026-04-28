// #include <iostream>

// using namespace std;

// struct Complex {
//     double real;
//     double imaginary;
// };


// void add(Complex &, Complex &, Complex &);

// void add(Complex &a, Complex &b, Complex &c) {
//     c.real = a.real + b.real;
//     c.imaginary = a.imaginary + b.imaginary;
// }



// int main() {
//     Complex a = {1.0, 2.0};
//     Complex b = {3.0, 4.0};
//     Complex c;

//     add(a, b, c);

//     cout << c.real << " + " << c.imaginary << "i" << endl;  

//     return 0;
// } // 일반 함수 (void, 참조 전달)


// #include <iostream>

// using namespace std;

// struct Complex {
//     double real;
//     double imaginary;
// };

// Complex add(Complex, Complex);

// Complex add(Complex a, Complex b) {
//     Complex c;
//     c.real = a.real + b.real;
//     c.imaginary = a.imaginary + b.imaginary;
//     return c;
// }

// int main() {
//     Complex a = {1.0, 2.0};
//     Complex b = {3.0, 4.0};
//     Complex c = add(a, b);

//     cout << c.real << " + " << c.imaginary << "i" << endl;

//     return 0;
// } // 일반 함수 (return, 값 전달)

// #include <iostream>

// using namespace std;

// struct Complex{
//     double real;
//     double imaginary;

//     void add(Complex&, Complex&);
// };



// void Complex::add(Complex &a, Complex &b) {
//     real = a.real + b.real;
//     imaginary = a.imaginary + b.imaginary;
// }

// int main() {
//     Complex a = {1.0, 2.0};
//     Complex b = {3.0, 4.0};
//     Complex c;

//     c.add(a, b);

//     cout << c.real << " + " << c.imaginary << "i" << endl;

//     return 0;
// } // 멤버 함수 (void, 참조 전달)


#include <iostream>

using namespace std;

struct Complex{
    double real;
    double imaginary;

    Complex add(Complex&);
};

Complex Complex::add(Complex &other)

{
    Complex c;
    c.real = real + other.real;
    c.imaginary = imaginary + other.imaginary;
    return c;
}

int main() {
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};
    Complex c;

    c = a.add(b);

    cout << c.real << " + " << c.imaginary << "i" << endl;

    return 0;
} // 멤버 함수 (return, 참조 전달)

// #include <iostream>

// using namespace std;

// struct Complex{
//     double real;
//     double imaginary;

//     Complex operator+(Complex &other);

// };

// Complex Complex::operator+(Complex &other) {
//     Complex c;
//     c.real = real + other.real;
//     c.imaginary = imaginary + other.imaginary;
//     return c;
// }

// int main() {
//     Complex a = {1.0, 2.0};
//     Complex b = {3.0, 4.0};
//     Complex c;

//     c = a + b;

//     cout << c.real << " + " << c.imaginary << "i" << endl;

//     return 0;
// } // 연산자 오버로딩

