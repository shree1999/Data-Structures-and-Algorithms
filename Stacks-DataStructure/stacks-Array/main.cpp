// stack using array

#include <bits/stdc++.h>
#define SIZE 128
using namespace std;

class Stack
{
    // declaring values
    int top;
    int *arr;

public:
    // initailizing values
    Stack()
    {
        top = -1;
        arr = new int[SIZE];
    }

    // function to push data into stack-[array]
    void push(int data)
    {
        // Overflow check in case the limit exceeds
        if (top >= SIZE - 1)
        {
            cout << "[WRANING]Stack Overflows" << endl;
            return;
        }
        // increment the counter and add the data
        top += 1;
        arr[top] = data;
    }

    // function pops the top most element
    void pop()
    {
        // checking whether the stack is empty or not
        if (top == -1)
        {
            cout << "[WARNING]Stack is empty." << endl;
            return;
        }
        // if its not empty display the top element and decrement top by 1 to delete the top most data
        cout << "[INFO]Popped Element: " << arr[top] << endl;
        top--;
    }

    // function used to peek onto the top most element
    int peek()
    {
        // checking if stack is empty
        if(top < 0) {
            cout << "error : stack is empty";
            return 0;
        }
        return arr[top];
    }

    void display()
    {
        // looping over the stack conditionally
        if (top >= 0)
        {
            cout << "The Stack elements are: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
        // if stack is empty then else block is executed
        else
        {
            cout << "[WARNING]Please fill the elements first" << endl;
            return;
        }
    }
};

int main()
{
    Stack s;
    s.push(12);
    s.push(11);
    s.push(13);
    s.push(33);
    s.push(02);
    s.display();

    s.pop();
    s.display();

    s.push(24);
    s.display();

    cout << "Top most element: " << s.peek() << endl;
}
