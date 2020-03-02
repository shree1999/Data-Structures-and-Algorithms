/* Stack Implementation using Array
In this implementation we are initializing top as our moving index
which will keep track of
*/

#include <iostream>
#include <cstdlib>
#define SIZE 128
using namespace std;

class Stack {
    int top;
    int *arr;
public:
    Stack() {
        top = -1;
        arr = new int[SIZE];
    }

    void push(int data) {
        // this function allows to put data into top of the stack
        if(top >= SIZE - 1) { // checking for over-flow
            cout<<"Stack Over-Flows"<<endl;
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    int pop() {
        if(top == -1) {
            cout<<"Stack Under-Flow"<<endl;
            return -1;
        }
        int data = arr[top];
        top--;
        return data;
    }

    int peek() {
        return arr[top];
    }

    void display() {
        if(top >= 0) {
                cout<<"The Stack elements are: "<<endl;
            for(int i = top; i >= 0; i--) {
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }
        else {
            cout<<"Please Fill the elements first"<<endl;
            return;
        }
    }
};

int main() {
    Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);// note the output 60 will come first even if it was added at last.

    cout<<s.pop()<<endl;
    s.display();
    return 0;
}
