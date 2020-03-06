/* this program is based on generating Fibonacci Series using recursion and doing the same with iterative
approach
A Fibonacci series is given by of the form of
0, 1, 1, 2, 3, 5, 8,... where from 2nd index the numbers are the sum of previous two numbers.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// function to generate Fibonacci series using recursion
int fibonacci(int num) {
    if(num == 0) {
        return 0;
    }
    else if(num == 1) {
        return 1;
    }
    else {
        return(fibonacci(num - 1) + fibonacci(num - 2));
    }
}

int main() {
    int num = 10, i; // num denotes the maximum limit of the series.
                        // i denotes the index at which we are calling Fibonacci function

    for(i = 0; i < num; i++) {
        cout<<fibonacci(i)<<"  ";
    }
    cout<<endl;

    cout<<"Now for Iterative method"<<endl;
    int a = 0, b = 1, sum = 0;
    if(num == 0) {
        cout<<a<<endl;
    }
    else if(num == 1) {
        cout<<a<<", "<<b<<endl;
    }
    else {
        for(int i = 0; i < num; i++) {
            cout<<sum<<", ";
            sum = a + b;
            a = b;
            b = sum;
        }
    }
    return 0;
}


