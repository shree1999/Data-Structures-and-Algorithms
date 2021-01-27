/* this program is based on generating Fibonacci Series using recursion and doing the same with iterative
approach
A Fibonacci series is given by of the form of
0, 1, 1, 2, 3, 5, 8,... where from 2nd index the numbers are the sum of previous two numbers.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> memo; // used to store pre-calculated value of fibo numbers (dec time-complexity from 2^n to O(n))
// function to generate Fibonacci series using recursion
int fibonacci(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    if (memo[num] != 0)
        return memo[num];
    memo[num] = fibonacci(num - 1) + fibonacci(num - 2);
    return memo[num];
}

int main()
{
    int num = 10;     // num denotes the maximum limit of the series.
                      // i denotes the index at which we are calling Fibonacci function
    memo.resize(num); // to make memo of size num
    for (int i = 0; i < num; i++)
    {
        cout << fibonacci(i) << "  ";
    }
    cout << endl;

    cout << "Now for Iterative method" << endl;
    int fib[num];
    fib[0] = 0;
    if (num > 1)
        fib[1] = 1;

    for (int i = 2; i < num; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < num; i++)
    {
        cout << fib[i] << "  ";
    }
    cout << endl;
    return 0;
}
