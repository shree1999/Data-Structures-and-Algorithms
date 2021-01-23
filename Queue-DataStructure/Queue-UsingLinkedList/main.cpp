/* Implementing Queue DataStructure using linked list
Queue works on the principle of FIFO(first-in-first-out)
hence the function we are implementing are:
1. preAppend() to denote the queue is forming hence all the node added from head.
2. removeElement() removes the first element that was inserted at the starting.
3. display() show all the elements in the queue.

    50-->20-->30-->20-->10
lastElement         firstElement
*/

#include <iostream>
#include <cstdio>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *last, *first;
    int totalElements;

public:
    Queue()
    {
        last = NULL;
        first = NULL;
        totalElements = 0;
    }

    void preAppend(int data)
    { //function to pre-append data into queue
        Node *newNode = new Node(data);

        if (first == NULL)
        {
            first = newNode;
            last = newNode;
            totalElements++;
            return;
        }

        newNode->next = last;
        last = newNode;
        totalElements++;
    }

    void removeElement()
    {
        if (first == NULL)
        {
            cout << "Queue Already empty" << endl;
            return;
        }
        Node *temp = last;
        for (int i = 1; i < totalElements - 1; i++)
        {
            temp = temp->next;
        }
        // cout<<temp->data<<endl;
        free(temp->next);
        temp->next = NULL;
        first = temp;
    }

    void display()
    {
        if (first == NULL)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node *temp = last;
        for (int i = 0; i < totalElements && temp != NULL; i++)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.preAppend(10);
    q.preAppend(20);
    q.preAppend(30);
    q.preAppend(40);
    q.preAppend(50); // 50->40->30->20->10

    q.removeElement(); // 50->40->30->20
    q.display();
}
