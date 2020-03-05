/* This programs is based on finding the factorial of a number using recursion
    factorial of a number is given as
    5! = 5 * 4 * 3 * 2 * 1 = 120
*/

#include <iostream>
#include <cstdlib>
using namespace std;


// defining a recursive function called factorial.
int factorial(int num) {
    if(num < 0) {
        return false;
    }
    if(num == 0 || num == 1) {
        return 1;
    } else {
        return num*factorial(num - 1); // function is called every time by reducing the digit by one.
    }
}

int main() {
    int num = 10;
    int fact = factorial(num);

    cout<<"Factorial of "<<num<<" is "<<fact<<endl;
    return 0;
}
