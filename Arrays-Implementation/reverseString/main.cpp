#include<bits/stdc++.h>
using namespace std;
int main() {
    // let us take input from the user for this one.
    string str;
    cout<<"Enter String of your choice..."<<endl;
    getline(cin, str);

    cout<<"Entered String is: "<<str<<endl;

    reverse(str.begin(), str.end()); 

    cout << "Reversed String is: "<<endl;
    cout << str;

    return 0;
}
