#include<bits/stdc++.h>
using namespace std;

void removeElements(vector<int>&v, int num) {
    int c = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i]!=num) {
            v[c++] = v[i];
        }
    }
    for(int i = 0; i < c; i++) {
        cout<<v[i]<<"  ";
    }
}

int main() {
    vector<int>vect;
    int ele, num;
    int l;
    cout<<"enter the length of array"<<endl;
    cin>>l;
    cout<<"Enter elements: "<<endl;
    for(int i = 0; i < l; i++) {
        cin>>ele;
        vect.push_back(ele);
    }

    cout<<"Enter Element to be deleted\n";
    cin>>num;

    removeElements(vect, num);

    return 0;
}
