// This is binary search algorithm in cpp. This algorithm is implemented in both way, using simple
// while loop and recursion.

#include<iostream>
#include<stdio.h>

using namespace std;


//This function is implemented using recursion..
void binarySearch(int arr[], int low, int high, int num){
    int mid = (low+high)/2;
    if(arr[mid] == num){
        cout<<num<<" is found at index "<<mid<<endl;
        return;
    }
    if(arr[mid] < num){
        binarySearch(arr, mid+1, high, num);
    }
    else if(arr[mid] > num){
        binarySearch(arr, 0, mid-1, num);
    }
}

// This function is implemented using while loop.
// Binary Search in C++
void binarySearch2(int arr[], int low, int high, int num) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == num){
        cout<<num<<" is found at index "<<mid<<endl;
        break;
    }

    if (arr[mid] < num){
      low = mid + 1;
    }

    else{   
      high = mid - 1;
    }
  }

}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 14, 15, 18};
    int len = sizeof(arr)/sizeof(arr[0]);
    binarySearch(arr, 0, len-1, 18);
    binarySearch2(arr, 0, len-1, 15);
    return 0;
}