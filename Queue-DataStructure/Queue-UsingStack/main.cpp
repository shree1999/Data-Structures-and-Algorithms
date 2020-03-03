/* Creating Queue using Two Stacks
Here let us see how it works
1. s1 stores all the data that has been enqueue
2. when its time to remove then copy all the elements from the top of s1 and paste it in
   s2 so that s2 will have first inserted element at the top. After this we can simply remove
   top element from s2.

*/

#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s1, s2; // using stack data structure from STL library
public:

    Queue() {}

    void enQueue(int data) {
        s1.push(data);
    }

    void deQueue() {
        if(s1.empty() && s2.empty()) { // check for empty condition
            cout<<"Please Insert Data"<<endl;
            return;
        }
        if(s2.empty()) { // checking for stack 2 is empty or not
            while(!s1.empty()) {
                s2.push(s1.top());  // in this we copy s1 to s2
                s1.pop(); // pop element from s1
            }
        }
        cout<<s2.top()<<endl;  // if s2 is not empty then simply remove top of s2.
        s2.pop();
    }

    void peek() {
        if(s1.empty()) {
            cout<<"Please Insert Element"<<endl;
            return;
        }
        cout<<"Top Element: "<<s1.top()<<endl;
    }

};

int main() {
    Queue q;

    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.deQueue();

    return 0;
}
