// queue using stack

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    // using s1 to push the data into stack and using s2 to reverse the data from s1 and store it in s2 to appear it like queue
    stack<int> s1, s2; // using stack data structure from STL library
public:
    Queue() {} // initialized queue

    void enQueue(int data)
    {
        s1.push(data);
    }

    void deQueue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Please Insert Data" << endl;
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                // we will push top element from s1 to s2 until s1 becomes empty
                s2.push(s1.top());
                // at each push in s2 we will pop top from s1
                s1.pop();
            }
        }
        cout << s2.top() << endl; // if s2 is not empty then simply remove top of s2.
        s2.pop();
    }

    void peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                // we will push top element from s1 to s2 until s1 becomes empty
                s2.push(s1.top());
                // at each push in s2 we will pop top from s1
                s1.pop();
            }
        }
        cout << "Top Element: " << s2.top() << endl;
    }
};

int main()
{
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    q.peek();
    q.deQueue();
    q.peek();
    q.deQueue();
    q.peek();

    return 0;
}
