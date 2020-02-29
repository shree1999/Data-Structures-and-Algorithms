/* Problem - given an ORDERED integer array return the pair of numbers whose sum
add to some number k if not found return false.
input array = [1,2,3,9], sum = 8
output false, false
input array = [1,2,4,4], sum = 8
output 4, 4
Note: we cannot have pairs of same index numbers.
*/

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

/* Using naive approach O(n^2) time complexity and O(1) space complexity. */
tuple<int, int>checkForPairs(int *arr, int sizeOfArr, int sum) {
    for(int i = 0; i < sizeOfArr - 1; i++) {
        for(int j = i + 1; j < sizeOfArr; j++) {
            if((arr[i] + arr[j]) == sum ) {
                return make_tuple(arr[i], arr[j]);
            }
        }
    }
    return make_tuple(false, false);
}

/* Using better approach that takes the concept that array is ordered. O(sizeOfArr) time complexity*/
tuple<int, int>betterCheckForPairs(int *arr, int sizeOfArr, int sum) {
    int low = 0, high = sizeOfArr - 1;
    while(low < high) {
        int temp = arr[low] + arr[high];
        if(temp > sum) {
           high--;
        }
        else if(temp < sum) {
            low++;
        }
        else {
            return make_tuple(arr[low], arr[high]);
        }
    }
    return make_tuple(false, false);
}

/*3. Till now we had assume that array is sorted now if remove that constraints the how to take that approach
method 1: again with naive approach discussed earlier.
method 2: using a data structure called set that will keep the track of all the visited numbers in array.
we are using set because it helps in maintaining integrity.
*/

tuple<int, int>usingUnsortedArray(int *arr, int sizeOfArr, int sum) {
    unordered_set<int>comp;
    for(int i = 0; i < sizeOfArr; i++) {
        int target = sum - arr[i];
        if(comp.find(target) != comp.end()) {
            return make_tuple(arr[i], target);
        }
        comp.insert(arr[i]);
    }
    return make_tuple(false, false);
}

int main() {
    int arr1[] = {1,2,3,9}, x, y;
    int arr2[] = {1,2,4,4}, sum = 8;
    int arr3[] = {1,2,4,5,0,2};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);

    tie(x, y) = checkForPairs(arr1, n1, sum);
    cout<<"The result is: "<<x<<", "<<y<<endl;
    tie(x, y) = checkForPairs(arr2, n2, sum);
    cout<<"The result is: "<<x<<", "<<y<<endl;

    cout<<"-------  better approach below  ----------"<<endl;
    tie(x, y) = betterCheckForPairs(arr2, n2, sum);
    cout<<"The result is: "<<x<<", "<<y<<endl;

    cout<<"-------  Approach when array is unsorted-------"<<endl;
    tie(x, y) = usingUnsortedArray(arr3, n3, sum);
    cout<<"The result is: "<<x<<", "<<y<<endl;
    return 0;
}
