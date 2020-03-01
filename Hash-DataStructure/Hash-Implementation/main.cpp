/* Implementation of Hashing data structure */
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int ARRAY_SIZE = 128;

/* creating a class called hash node which will have two properties
1. Key
2. Value
*/

class HashNode {
public:
    int key;
    int value;

    // creating a constructor to store key and value.
    HashNode(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashTable {
    HashNode **arr; // declaring array of hash node
public:

    HashTable() {
        arr = new HashNode*[ARRAY_SIZE]; // creating array of hash node.
        for(int i = 0; i < ARRAY_SIZE; i++) {
            arr[i] = NULL;
        }
    }

    // creating a hash function(this is an example of open addressing)
    int hashFunction(int key) {
        return key % ARRAY_SIZE;
    }

    // creating a function for inserting the key, value pair in hash table
    void insertElement(int key, int value) {
        int h = hashFunction(key);
        while(arr[h] != NULL && arr[h]->key != key) {
            h = hashFunction(h + 1);
        }
        if(arr[h] != NULL) {  // if the key is already present then delete the (key, value) pair
            delete arr[h];
        }
        arr[h] = new HashNode(key, value); // create a new (key, value) pair.
    }

    int get(int key) {
        int h = hashFunction(key);
        while(arr[h] != NULL && arr[h]->key != key) {
            h = hashFunction(h + 1);
        }
        if(arr[h] == NULL) {
            return -1;
        }
        return arr[h]->value;
    }

    void removeValue(int key) {
        int h = hashFunction(key);
        if(arr[h] == NULL) {
            cout<<"No Element Found"<<endl;
            return;
        }
        while(arr[h] != NULL) {
            if(arr[h]->key == key) {
                break;
            }
            h = hashFunction(h + 1);
        }
        delete arr[h];

        cout<<"Element deleted"<<endl;

    }

    void display() {
        for(int i = 0; i < ARRAY_SIZE; i++) {
            if(arr[i] != NULL && arr[i]->key != -1) {
                cout<<arr[i]->key<<"----->"<<arr[i]->value<<endl;
            }
        }
    }

};

int main() {
    HashTable h;
    h.insertElement(1,1);
    h.insertElement(2,2);
    h.insertElement(2,3);
    h.insertElement(2,8);  // note then when displayed the value of key->2 should be only 8.
    h.insertElement(12,21);

    h.display();

    cout<<h.get(2);

    return 0;

}

