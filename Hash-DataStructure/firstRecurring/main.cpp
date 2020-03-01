#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, int>m;
    int arr[] = {1,2,3,4,5,6,4,5,2,3,4};
    int sizeArr = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < sizeArr; i++) {
        if(m.find(arr[i]) == m.end()) {
            m[arr[i]] = 1;
        }
        else {
            cout<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}
