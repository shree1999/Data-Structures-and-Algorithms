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
class Node {
public:
    int data;
    Node *next;
};

class Stack {
    Node *top; // declaring two pointers head and tail of class Node.
    int totalNodes;
public:
    Stack() {
        top = NULL;
        totalNodes = 0;
    }

    void push(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if(top == NULL) {
            totalNodes++;
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
        totalNodes++;
    }

    void pop() {
        if(top == NULL) {
            cout<<"Stack Under-Flow or Empty"<<endl;
            return;
        }
        Node *curr = top;
        cout<<top->data<<endl;
        top = top->next;
        free(curr);
        totalNodes--;
    }
    void display() {
        if(top == NULL) {
            cout<<"Empty Stack Please push elements"<<endl;
            return;
        }
        Node *temp = top;
        for(int i = 0; i < totalNodes && temp!=NULL; i++) {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();  //removes 30
    s.display();

    return 0;
}



