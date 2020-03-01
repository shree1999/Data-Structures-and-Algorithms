#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>&v) {
    int c = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i]!=0) {
            v[c++] = v[i];
        }
    }
    while(c < v.size()){
        v[c++] = 0;
    }

    for(int i = 0; i < c; i++) {
        cout<<v[i]<<"  ";
    }
}

int main() {
    vector<int>vect;
    int ele, num;
    cout<<"Enter elements: "<<endl;
    for(int i = 0; i < 10; i++) {
        cin>>ele;
        vect.push_back(ele);
    }

    moveZeroes(vect);

    return 0;
}
