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
using namespace std;
/* defining a function for naive approach -> O(n^2) time complexity
                                          -> O(1) space complexity
*/ 
bool findingMatch(char *arrA, char *arrB, int sizeA, int sizeB) {

}
int main() {

    char arrA[] = {'a', 'b', 'c', 'x'};
    char arrB[] = {'z', 'y', 'i'};

    cout<<"array A"<<arrA;
    cout<<"\narray B"<<arrB;

    return 0;
}