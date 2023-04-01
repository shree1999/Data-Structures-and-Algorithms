/* Implementing dynamic array in c++ which is basically a vector STL library.
   but the below implementation of arrays in c++ is done by using class which will have the
   following functions.

    1. void push(int data): This function takes one element and inserts it at the last.
    2. void push(int data, int index): It inserts data at the specified index.
    3. int get(int index): It is used to get the element at the specified index.
    4. void pop(): It deletes the last element. Time complexity is O(1).
    5. int size(): It returns the size of the vector i.e, number of elements in the vector. Time complexity is O(1).
    6. int getcapacity(): It returns the capacity of the vector. Time complexity is O(1).
    7. void print(): It is used to print array elements. Time complexity is O(N), where N is the size of the vector.

 */

 #include <bits/stdc++.h>
 using namespace std;

 class DynamicArray {
    int *arr; //creating array pointer
    int capacity; // holds the actual size of the array.
    int totalNumbers; // hold the total number of elements present in array.

public:
    DynamicArray() {
        arr = new int[2];
        capacity = 2;
        totalNumbers = 0;
    }

    void push(int data) {
        if(totalNumbers == capacity) {
            // check for end case when initially array is filled with assigned capacity
            int *temp = new int[2 * capacity];
            for(int i = 0; i < capacity; i++) {
                temp[i] = arr[i];   //copy array elements in new array -> temp
            }
            delete[] arr; //delete memory allocated for older array
            capacity = capacity * 2;
            arr = temp; // pointing our arr to newly allocated memory
        }
        arr[totalNumbers] = data; //inserting data.
        totalNumbers++;
    }

    void push(int data, int index) {
        // in this function we replace the number which is already present in that index.
        if(index == capacity) {
            push(data); // checking for end case.
        }
        else {
            arr[index] = data; // insert data
        }
    }

    void insertElement(int data, int index) {
        // in this function we don't replace the original number
        if(index == capacity) {
            push(data);
        }
        for(int i = totalNumbers; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = data;
        totalNumbers++;
    }

    int pop() {
        // return number at the end of array and reduces the size of array.
        int ele = arr[totalNumbers-1];
        totalNumbers--;
        return ele;
    }

    void pop(int index) {
        // deleting element from particular index
        if(index > -1 && index < totalNumbers) {
            totalNumbers--;
            for(int j = index; j < totalNumbers; j++) {
                arr[j] = arr[j + 1];
            }
        }
    }

    int get(int index) {
        // get the data of the particular index.
        if(index > -1 && index < totalNumbers) {
            return arr[index];
        }
    }

    int length() {
        // get the size of array.
        return totalNumbers;
    }

    void print() {
        for(int i = 0; i < totalNumbers; i++) {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    // end of class
 };

 int main() {
    DynamicArray a; // creating instance of the class.
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.insertElement(50, 2);
    cout<<"The array is: ";
    a.print();

    int ele = a.pop();// removing last element
    cout<<"Element Deleted: "<<ele<<endl;
    cout<<"The array after deletion is: ";
    a.print();

    a.pop(0);
    cout<<"The array after deleting index-0 element: ";
    a.print();

    cout<<"The size of array is: "<<a.length()<<endl;

    return 0;
 }
