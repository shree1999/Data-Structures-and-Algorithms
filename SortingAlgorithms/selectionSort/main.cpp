/* This program is based on the sorting algorithm called Selection Sort

  Time Complexity = O(n^2)
  Space Complexity = O(1)
*/
#include<iostream>
using namespace std;

void swapFunction(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }

            swapFunction(&arr[min_index], &arr[i]);  // swap the minimum index element and first index element
        }
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    cout<<"Sorted Array is: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  ";
    }

    return 0;
}
