#include<bits/stdc++.h>
using namespace std;
int main() {
    // let us take input from the user for this one.
    string str;
    cout<<"Enter String of your choice..."<<endl;
    getline(cin, str);

    cout<<"Entered String is: "<<str<<endl;

    // reverse(str.begin(), str.end()); method - 1 using built-in library

    cout<<"Reversed String is: "<<endl;
    for(int i = str.length() - 1; i >= 0; i--) {
        cout<<str[i];
    }

    return 0;
}
