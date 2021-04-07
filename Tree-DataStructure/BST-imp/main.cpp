/* This program is based on the implementation of BST(binary search tree)
using linked list as our data-structure
now, the functions that BST can be introduced with are:
1. Insert() this function let us construct the binary search tree with the fact that the left subtree
   values from the node should be less and the right subtree values should be greater the node

2. lookup() this function let us return True or false if the given node exist or not.
3. remove() let us remove a node Note: we should always maintain the constraints of the BST after removal(hence
    it may also required to reorder some node.)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binarySearchTree
{
    Node *root;

public:
    binarySearchTree()
    {
        root = NULL;
    }
    void insertNode(int data)
    {
        Node *newNode = new Node(data);
        Node *temp = root; /* temp Pointer to start traversing from root and traverses downward path to search
                             where the new node to be inserted */

        Node *x = NULL; // this pointer will help us in maintaining the trailing pointer of temp.

        while (temp != NULL)
        {
            x = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (x == NULL) // if tree is empty
            root = newNode;

        else if (data < x->data)
            x->left = newNode;
        else
            x->right = newNode;
    }

    void deleteNode(int data)
    { // this function deletes node from the BST
        if (root == NULL)
        {
            cout << "Tree Empty Please Insert values" << endl;
            return;
        }
        Node *temp = root;   // pointer for traversing data if present
        Node *parent = NULL; // trailing pointer that points to the parent node(intermediate nodes)
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }

            else if (data > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                // looking for child nodes
                if (temp->left == NULL && temp->right == NULL)
                {
                    cout << "We are deleting a leaf node" << endl;
                    if (parent->left == temp)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                    free(temp);
                    return;
                }
                else if (temp->left == NULL || temp->right == NULL)
                {
                    cout << "We are deleting parent node which have one child" << endl;
                    if (temp->left != NULL&&data<root->data)
                    {
                        parent->left = temp->left;
                    }
                    else if(temp->right != NULL&&data>root->data)
                    {
                        parent->right = temp->right;
                    }
                    else if(temp->right != NULL&&data<root->data)
                    {
                      parent->left = temp->right;
                    }
                    else{
                      //checking if temp has no value in the right and data is greater than parent
                      //then the parent right value is temp's left value
                      parent->right = temp->left; 
                    }
                    free(temp);
                    return;
                }
                else
                {
                    cout << "Deleting Node which has two children" << endl;
                    // in this case we need to find the pre-order successor.
                    Node *t = temp->right;
                    if (t->left == NULL && t->right == NULL)
                    {
                        temp->data = t->data;
                        temp->right = NULL;
                        free(t);
                        return;
                    }
                    else if (t->left == NULL && t->right != NULL)
                    {
                        temp->data = t->data;
                        temp->right = t->right;
                        free(t);
                        return;
                    }
                    while (t->left != NULL)
                    {
                        parent = t;
                        t = t->left;
                    }
                    temp->data = t->data;
                    parent->left = NULL;
                    free(t);
                    return;
                }
            }
        }
        cout << "No Nodes Found to delete" << endl;
        return;
    }

    bool lookup(int data)
    {
        if (root == NULL)
        {
            cout << "Tree Empty please Insert values" << endl;
            return false;
        }
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data > data)
            {
                temp = temp->left;
            }
            else if (temp->data < data)
            {
                temp = temp->right;
            }
            else if (temp->data == data)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    { // this display function uses in-order traversal left->root->right
        /* here we are using stack data structure for traversing */
        stack<Node *> s;
        Node *temp = root;

        while (temp != NULL || s.empty() == false)
        {

            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left; // going towards left first
            }
            temp = s.top();
            cout << temp->data << "  "; // printing the left most data.
            s.pop();

            temp = temp->right; // going towards right.
        }
    }
};

int main()
{
    binarySearchTree b;
    /*    20
         /  \
        10   30
       /    /  \
      1    25  40   tree structure */

    b.insertNode(20);
    b.insertNode(10);
    b.insertNode(30);
    b.insertNode(25);
    b.insertNode(40);
    b.insertNode(1);

    b.display();
    cout << endl;

    b.deleteNode(30);
    b.display();

    return 0;
}
