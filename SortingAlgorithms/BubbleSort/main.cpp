/* This program is based on Bubble sort Sorting algorithm
time complexity O(n^2)
space Complexity O(1)
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// bubble sort algorithm
void bubbleSort(int arr[], int n) {

    for(int i = 0; i < n - 1; i++) {

        for(int j = 0; j < n - 1 - i; j++) {

            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


/* better bubble sort where it can be optimized by stopping the
    algorithm if inner loop did not cause any swap. */

void betterBubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - 1 - i; j++) {

            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}


int main() {

    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    betterBubbleSort(arr, n);
    cout<<"Sorted Array is: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
