/* This program is made to implement stack using linked list
The functions that will be used for implementing stack are:
1. push() ==> preAppend()
2. pop() ==> removeFromBeginning()
3. display()
*/

#include <iostream>
#include <cstdlib>

using namespace std;
// creating a class node that defines it.
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL; // it should be initialized as NULL, unless it occurs SIGSEGV error.
    }
};

class Stack
{
    Node *top; // declaring two pointers head and tail of class Node.
public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Under-Flow or Empty" << endl;
            return;
        }
        Node *curr = top;
        cout << top->data << endl;
        top = top->next;
        free(curr);
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "Empty Stack Please push elements" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop(); //removes 30
    s.display();

    return 0;
}
