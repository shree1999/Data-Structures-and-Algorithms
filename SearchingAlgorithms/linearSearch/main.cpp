/*This algorithm is based on most basic searching called Linear Search
  Time Complexity = O(n) worst case
  space Complexity = O(1)
*/
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int keyToSearch = 10;
    int foundIndex = linearSearch(arr, n, keyToSearch);

    if(foundIndex >= 0) {
        cout<<"Element "<<keyToSearch<<" is at index "<<foundIndex<<endl;
    } else {
        cout<<"Element "<<keyToSearch<<" not found"<<endl;
    }
    return 0;
}
