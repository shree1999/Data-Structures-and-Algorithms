/* Implementation of priority Queue using LinkedList
Begin
   class Priority_Queue has following functions:
   function enQueue() to insert items at priority queue with their priorities:
      1) If queue is empty insert data from the left end of the queue.
      2) If queue is having some nodes then insert the new node at the end of those nodes having priority
         same with the new node and also before all the nodes having priority lesser than the
         current priority of the new node.
      function removeElement() to delete items from queue.
   If queue is completely empty, print underflow otherwise delete the front element and update front.
End
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int priority;
    int data;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

class Priority_Queue
{
    Node *first;

public:
    Priority_Queue()
    {
        first = NULL;
    }

    void enQueue(int data, int p)
    {
        Node *newNode = new Node(data, p);
        if (first == NULL || p < first->priority)
        {
            newNode->next = first;
            first = newNode;
            return;
        }
        Node *temp = first;
        while (temp->next != NULL && temp->next->priority <= p)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deQueue()
    {
        // delete element first which has the highest priority
        if (first == NULL)
        {
            cout << "Queue Empty Please insert Elements" << endl;
            return;
        }
        Node *temp = first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

    void display()
    {
        if (first == NULL)
        {
            cout << "Queue Empty" << endl;
            return;
        }
        Node *temp = first;
        while (temp != NULL)
        {
            cout << temp->priority << " " << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Priority_Queue p;
    p.enQueue(10, 3);
    p.enQueue(20, 2);
    p.enQueue(40, 1);
    p.enQueue(50, 4);

    p.deQueue();
    p.display();
}
