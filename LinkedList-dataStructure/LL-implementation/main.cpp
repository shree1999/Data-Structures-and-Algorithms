// It's a c++ program to implement linked list

#include <bits/stdc++.h>
using namespace std;

/* 
we consider a node with two properties
1. Data(now integer)
2. link containing the address of the other node that it points.
*/

class Node
{
public:
    int data;
    Node *link;
    Node(int data)
    {
        this->data = data; // assigning data
        this->link = NULL; // initialize link to null
    }
};

class LinkedList
{
    Node *head;
    Node *tail;
    int totalNodes;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    void append(int element)
    {
        // append function insert the element at the end of LL
        // time complexity O(1)

        // creating a new node to store element/data
        Node *newNode = new Node(element);

        // checking if LL is empty then insert data into head and tail
        // as for the first node the head and tail is same
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }

        // link the newNode with the tail via pointer reference and assign the newNode as tail
        tail->link = newNode;
        tail = newNode;
        totalNodes++;
    }

    void preAppend(int element)
    {
        // this function will append the nodes at the begining of LL
        // time complexity O(1)
        Node *newNode = new Node(element);

        // checking if LL is empty then insert data into head and tail
        // as for the first node the head and tail is same
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }

        // link the newNode with exisiting head node and assign the head to the newNode
        newNode->link = head;
        head = newNode;
        totalNodes++;
    }

    void insertNode(int element, int pos)
    {
        // insert nodes anywhere in the LL
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        else if (pos == 0)
        {
            // for first position
            preAppend(element);
        }
        else if (pos >= totalNodes)
        {
            // for last position
            append(element);
        }
        else
        {
            Node *newNode = new Node(element);
            Node *prev = head;

            // we are finding the previous node w.r.t to position where we have to insert our node
            for (int i = 0; i < pos - 1; i++)
            {
                prev = prev->link;
            }

            /* 
            for simplicity lets consider, here we have 3 nodes 
            [data, link] = [data, pointer reference to next node]
            1 - prev node that we found [data,link to next node]
            2 - the next node w.r.t prev node [data, link to next node / null]
            3 - the newNode that we have to insert [data,link] after prev node
            */

            // assigning prevNode's pointer refernce to newly created node's pointer reference
            // so that newly created node points towards the next node where prev node was pointing previously
            newNode->link = prev->link;

            // now in prevNode's pointer reference we will assign the reference of newly created node
            prev->link = newNode;

            /*
            prev node                    new node                       next node
            [data,pointer to new node]-->[data, pointer to next node]-->[data, pointer to next node/null]
            */

            // we will increase the count of total number of nodes
            totalNodes++;
        }
    }

    void removeNode(int pos)
    {
        if (pos < 1 || pos > totalNodes)
        {
            cout << "[WARNING]Oops! Node cannot be deleted." << endl;
            return;
        }
        Node *temp = head;
        if (pos == 1)
        {
            head = head->link;
            free(temp);
            totalNodes--;
            return;
        }

        // traverse to the position just before the node that is to be deleted
        for (int i = 1; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->link;
        }

        // check if the temp or pointer reference is null or not
        // if it is true it means that the node which is to be deleted is not present
        if (temp == NULL || temp->link == NULL)
        {
            return;
        }

        // creating link between temp and node after the node that is being deleted.
        Node *link = temp->link->link;

        // delete the pointer reference
        free(temp->link);

        // assign the newly created link(pointer reference) to temp->link
        temp->link = link;

        totalNodes--;
        return;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Please Insert Element First." << endl;
        }
        Node *temp = head;
        for (int i = 0; i < totalNodes; i++)
        {
            cout << temp->data << "-->";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l;
    // appending elements
    cout << "Appending Node:" << endl;
    l.append(2);
    l.append(4);
    l.append(6);
    l.append(8);
    l.append(10);

    // displaying elements
    l.display();

    cout << "Inserting Node:" << endl;

    l.insertNode(3, 2);
    l.display();
    l.insertNode(1, 0);
    l.display();

    cout << "Delete Node:" << endl;
    l.removeNode(4);
    l.removeNode(1);
    l.removeNode(5);

    l.display();

    return 0;
}
