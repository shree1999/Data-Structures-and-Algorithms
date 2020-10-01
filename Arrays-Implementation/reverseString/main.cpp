#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter String of your choice..." << endl;
    getline(cin, str); // Input is taken from the user

    string str2 = str; // Making another string which is same as the input string

    //  Print the entered string
    cout << "Entered String is: " << str << endl;

    // Inbuilt Function which reverses the string
    reverse(str.begin(), str.end());

    // Another way to reverse a string by swapping element with start and front
    int len = str2.length();
    int n = len - 1;
    int i = 0;
    while (i <= n)
    {
        swap(str2[i], str2[n]); // Inbuilt Function that swaps 2 elements
        n--;                    // Decrementing value of n by 1 after each iteration
        i++;                    // Incrementing value of i by 1 after each iteration
    }

    cout << "Reversed String is: " << endl;
    cout << str << endl;
    cout << str2 << endl;

    return 0;
}
