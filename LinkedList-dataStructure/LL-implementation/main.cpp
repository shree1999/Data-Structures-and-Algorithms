/* It's a c++ program to implement linked list
we consider a node with two properties
1. Data(now integer)
2. link containing the address of the other node that it points.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{ // class node
public:
    int data;
    Node *link;
    Node(int data)
    {
        this->data = data; // filling data with element
        this->link = NULL; // initially setting link to NULL
    }
};

class LinkedList
{ // class for implementing linked list.
    Node *head;
    Node *tail;
    int totalNodes;

public:
    LinkedList()
    {
        // initializing the node to null value.
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    void append(int element)
    {
        // inserting at the end of linked list(O(1) time complexity)
        Node *newNode = new Node(element); // creating a node to store data.

        if (head == NULL)
        { // checking if head is null i.e. linked list is empty...
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }
        //if not then...
        tail->link = newNode;
        tail = newNode;
        totalNodes++;
    }

    void preAppend(int element)
    {
        // inserting at the beginning of linked list(O(1) time complexity)
        Node *newNode = new Node(element);
        if (head == NULL)
        { // checking if head is null i.e. linked list is empty...
            head = newNode;
            tail = newNode;
            totalNodes++;
            return;
        }

        newNode->link = head;
        head = newNode;
        totalNodes++;
    }

    void insertNode(int element, int pos)
    {
        /* function that let user insert a node in between the nodes of the linked list(O(n) time complexity)
    we will consider position(pos) = 0 means that it is the head node position. */
        if (pos < 0)
        {
            cout << "Cannot Insert node at this position" << endl;
            return;
        }
        if (pos == 0)
        { // checking for 1st position
            preAppend(element);
        }
        else if (pos >= totalNodes)
        { //checking for last position
            append(element);
        }
        else
        {
            Node *newNode = new Node(element);
            Node *prev = head;

            for (int i = 0; i < pos - 1; i++)
            { // going to position - 1;
                prev = prev->link;
            }
            newNode->link = prev->link;
            prev->link = newNode;
            totalNodes++;
        }
    }

    void removeNode(int pos)
    {
        // function that helps in removing a node from the list.
        if (pos < 1)
        {
            cout << "Cannot Remove node at this position" << endl;
            return;
        }
        if (pos > totalNodes)
        {
            cout << "Cannot Delete node in this position" << endl;
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
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->link;
        }
        if (temp == NULL || temp->link == NULL)
        {
            return;
        }
        Node *link = temp->link->link; // creating link between temp and node after the node that is being deleted.
        free(temp->link);
        temp->link = link;
        totalNodes--;
        return;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Please Insert element first" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < totalNodes; i++)
        {
            cout << temp->data << "--->";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l;
    // appending elements
    cout << "Appending" << endl;
    l.append(2);
    l.append(4);
    l.append(6);
    l.append(8);
    l.append(10);

    // displaying elements
    l.display();

    cout << "Inserting node" << endl;

    l.insertNode(3, 2);
    l.display();
    l.insertNode(1, 0);
    l.display();

    cout << "Delete Node" << endl;
    l.removeNode(4);
    l.display();
}
