/* This program is based on the sorting algorithm called MergeSort
This algorithm is based on the divide and concur approach
Time complexity = O(n log n)
Space Complexity = O(n)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void mergeArray(int arr[], int low, int mid, int high) {
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int leftArr[size1], rightArr[size2];

    for(int i = 0; i < size1; i++) {
        leftArr[i] = arr[low + i];
    }
    for(int j = 0; j < size2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0; // index traversing in leftArray
    int j = 0; // index traversing in rightArray
    int k = low; // index traversing in original Array

    while(i < size1 && j < size2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // inserting remaining elements
    while(i < size1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < size2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {  // this function divides the array until it can't be divided into half

    if(low < high) {
        int mid = (low + (high - 1))/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        mergeArray(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n);

    cout<<"Sorted Array is: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
