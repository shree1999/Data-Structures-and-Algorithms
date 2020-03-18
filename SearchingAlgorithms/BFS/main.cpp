/* Breadth first search(BFS) a graph traversing technique to get all nodes
   it uses queue data structure.
   This program assumes that the node values is same as that of index of an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int vertices; // number of nodes

    list<int> *adj;
public:

    Graph(int v) {
        this->vertices = v;
        adj = new list<int>[vertices];
    }


    void addEdges(int from, int to) {
        adj[from].push_back(to);
    }

    // this function now talks about BFS
    void bfs(int s) {
        bool *visited = new bool[vertices]; // creating a visited array so that we could prevent looping.
        memset(visited, false, vertices); // setting initially visited to false

        list<int>q;
        visited[s] = true;
        q.push_back(s);
        list<int>::iterator i;

        while(q.empty() == false) {
            s = q.front();
            cout<<s<<"  ";
            q.pop_front();

            for(i = adj[s].begin(); i!=adj[s].end(); i++) {
                if(!visited[*i]) {
                    q.push_back(*i);
                    visited[*i] = true;
                }
            }
        }
    }
};

int main() {

    Graph g(4);

    g.addEdges(0 ,1);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(3, 0);

    g.bfs(0);

    return 0;
}
