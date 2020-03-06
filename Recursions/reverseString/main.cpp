/* Function to reverse a string using recursion */

#include <bits/stdc++.h>
#include <string>
using namespace std;

void stringReverse(string &line, int i = 0) {
    int n = line.length();
    if(i == n/2) {  // if i reaches half of string length stop the process because once we reached half we know that
                    // string has been reversed(swapped).
        return;
    }
    else {
        swap(line[i], line[n - 1 - i]); // swap built-in function in bits/stdc++.h
        stringReverse(line, i + 1);
    }

}

int main()
{
    string line;
    cout<<"Enter string"<<endl;
    getline(cin, line);   // function to use when accepting a sentence as a input.

    stringReverse(line);
    cout<<line<<endl;
    return 0;
}
