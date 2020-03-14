/* This algorithm is based on the sorting technique called head sort
Time complexity of heapify is O(Log n).
Time complexity of createAndBuildHeap() is O(n) and
overall time complexity of Heap Sort is O(n Log n).
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    // to create a heap call heapify
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);  // swap function is built-in

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 4, 3, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);
    cout<<"After Sorting: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  "<<endl;
    }
    return 0;
}
