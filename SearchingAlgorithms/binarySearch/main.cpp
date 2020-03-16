/*Algorithm for binary search
  Time Complexity = O(log n) if the array is already sorted
  otherwise, O(n log n) if the array is not sorted then apply merge sort then binary sort

  space Complexity = O(1)
*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    // since the array is sorted we will directly jump to binary search
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high)/2;

        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 7;
    int index = binarySearch(arr, n, key);

    if(index >= 0) {
        cout<<"Element "<<key<<" found at index "<<index<<endl;
    } else {
        cout<<"Element not "<<key<<"found"<<endl;
    }

    return 0;
}
