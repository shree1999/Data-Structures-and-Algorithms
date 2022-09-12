#include<iostream>
#include<cstdlib>
#include <bits/stdc++.h>
using namespace std;
// Approach 1: we are creating function pointer that points to the array that we will be returned.
int *mergeArray(int *arr1, int *arr2, int size1, int size2) {
    if(size1 == 0) {
        return arr2;
    }
    if(size2 == 0) {
        return arr1;
    }
    int *arr = new int[size1 + size2];
    int index1 = 0, index2 = 0, index = 0;
    while(index1 < size1  && index2 < size2) {
        if(arr1[index1] <= arr2[index2]) {
            arr[index] = arr1[index1];
            index1++;
        }
        else {
            arr[index] = arr2[index2];
            index2++;
        }
        index++;
    }
    for( int inx = index1; inx < size1; ++inx)
    {
      arr[index] = arr1[inx];
      ++index;
    }
    for( int inx = index2; inx < size2; ++inx)
    {
      arr[index] = arr2[inx];
      ++index;
    }
    return arr;
}

int main() {
    int arr1[] = {1,2,3,4,5,6,7};
    int arr2[] = {3,4,5,7,8,9,10, 11};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int *newArr = mergeArray(arr1, arr2, size1, size2);
    cout<<"Merged Array: "<<endl;
    for(int i = 0; i < size1+size2; i++) {
        cout<<newArr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}


// Approach 2: Using Vector and avoiding 3rd variable

void mergeArrays(vector<int> array1, vector<int> array2) {
  vector<int> mergedArray;
  int i = 0, j = 0;
  while (i < array1.size() && j < array2.size()) {
    if (array1[i] <= array2[j]) {
      mergedArray.push_back(array1[i]);
      i++;
    } else {
      mergedArray.push_back(array2[j]);
      j++;
    }
  }
  while (i < array1.size()) {
    mergedArray.push_back(array1[i]);
    i++;
  }
  while (j < array2.size()) {
    mergedArray.push_back(array2[j]);
    j++;
  }
  cout << "Merged array" << endl;
  for (auto iterator : mergedArray) {
    cout << iterator<<" ";
  }
}

int main() {
  vector<int> arr1{1,3};
  vector<int> arr2{5,23,32};
  mergeArrays(arr1, arr2);
  return 0;
}
