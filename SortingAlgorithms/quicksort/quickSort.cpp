                                                                           // Code for quick sort
#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *a, int *b)                                               // Function for swapping the array elements                          
        {
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }

int Partition(int a[], int lowerIndex, int upperIndex)                   // Partitioning of the array
        {
            int pivot, index, i;
            index = lowerIndex;
            pivot = upperIndex;
            for (i = lowerIndex; i < upperIndex; i++)
            {
                    if (a[i] < a[pivot])
                    {
                        swap(&a[i], &a[index]);
                        index++;
                    }
            }
            swap(&a[pivot], &a[index]);
            return index;
    }

int QuickSort(int a[], int lowerIndex, int upperIndex)              
    {
            int pindex;
            if (lowerIndex < upperIndex)
            {
                pindex = Partition(a, lowerIndex, upperIndex);
                QuickSort(a, lowerIndex, pindex - 1);                             // Recursively calling function
                QuickSort(a, pindex + 1, upperIndex);
            }
            return 0;
    }
int main()
    {
        int n, i;
      cout << "\nEnter the number of data elements to be sorted: ";            // Taking size of array as input
      cin >> n;
        int arr[n];
            for (i = 0; i < n; i++)
                {
                    cout << "Enter elements " << i + 1 << ": ";
                    cin >> arr[i];
                }
        QuickSort(arr, 0, n - 1);
        cout << "\nSorted Data ";
        for (i = 0; i < n; i++)
            cout << " " << arr[i];
        return 0;
    }
