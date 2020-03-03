/* Given 2 arrays, create a function that let's a user know (true/false) whether these two arrays contain any common items
For Example:
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'i'];
should return false.
-----------
const array1 = ['a', 'b', 'c', 'x'];
const array2 = ['z', 'y', 'x'];
should return true.

2 parameters - arrays - no size limit
return true or false  */

#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
/* defining a function for naive approach -> O(sizeA * sizeB) time complexity
                                          -> O(1) space complexity
*/
bool findingMatch(char *arrA, char *arrB, int sizeA, int sizeB) {
    if(sizeA == 0 && sizeB == 0) {
        return true;
    }
    else {
        for(int i = 0; i < sizeA; i++) {
            for(int j = 0; j < sizeB; j++) {
                if(arrA[i] == arrB[j]) {
                    return true;
                }
            }
        }
    }

    return false;
}

/* O(sizeA + sizeB) time complexity and  and O(sizeA) space complexity */
bool betterFindingMatch(char *arrA, char *arrB, int sizeA, int sizeB) {
    map<int, int>lookUp;
    for(int i = 0; i < sizeA; i++) {
        if(lookUp.find(arrA[i]) == lookUp.end()) {
            lookUp.insert({arrA[i], true});
        }
    }
    for(int i = 0; i < sizeB; i++) {
        if(lookUp.find(arrB[i]) != lookUp.end()) {
            return true;
        }
    }
    return false;
}

int main() {

    char arrA[] = {'a', 'b', 'c', 'x'};
    char arrB[] = {'z', 'y', 'x'};

    int sizeA = sizeof(arrA)/sizeof(arrA[0]);
    int sizeB = sizeof(arrB)/sizeof(arrB[0]);

    bool result1 = findingMatch(arrA, arrB, sizeA, sizeB);
    bool result2 = betterFindingMatch(arrA, arrB, sizeA, sizeB);
    if (result1 && result2) {
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
    return 0;
}
