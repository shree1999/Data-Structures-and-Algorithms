/* Input: Graph and a source vertex source
Output: Shortest distance to all nodes from source.
     If there is a negative weight cycle, then shortest distances are not
     calculated, negative weight cycle is reported.
Time complexity O(VE) where V -> number of nodes
                            E -> number of edges between these nodes.
*/

#include <iostream>
#include <climits>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V, E; // V -> number of nodes and E -> number of edges

public:
    Edge *edge;
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }

    void displayResult(int dist[], int V) {
        cout<<"Vertex \t Distance from Source"<<endl;
        for(int i = 0; i < V; i++) {
            cout<< i <<" \t " <<dist[i]<<endl;
        }
    }

    void bellmannFord(int src) {
        int dist[V];
        // initializing the dist array for INT_MAX
        for(int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
        }
        dist[src] = 0; // reaching the source node from source node is zero.

        for(int i = 0; i < V - 1; i++) {
            for(int j = 0; j < E; j++) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int weight = edge[j].weight;

                if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // now here we check for negative weight cycles
        for(int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout<<"Graph Contains Negative cycles" << endl;
                return;
            }
        }
        displayResult(dist, V);
    }
};

int main() {
    Graph graph(5, 8);  // graph(nodes, edges);
    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;
    graph.edge[0].weight = -1;

    graph.edge[0].src = 0;
    graph.edge[0].dest = 1;
    graph.edge[0].weight = -1;


    graph.edge[1].src = 0;
    graph.edge[1].dest = 2;
    graph.edge[1].weight = 4;

    graph.edge[2].src = 1;
    graph.edge[2].dest = 2;
    graph.edge[2].weight = 3;

    graph.edge[3].src = 1;
    graph.edge[3].dest = 3;
    graph.edge[3].weight = 2;

    // add edge 1-4 (or A-E in above figure)
    graph.edge[4].src = 1;
    graph.edge[4].dest = 4;
    graph.edge[4].weight = 2;


    graph.edge[5].src = 3;
    graph.edge[5].dest = 2;
    graph.edge[5].weight = 5;

    graph.edge[6].src = 3;
    graph.edge[6].dest = 1;
    graph.edge[6].weight = 1;


    graph.edge[7].src = 4;
    graph.edge[7].dest = 3;
    graph.edge[7].weight = -3;

    graph.bellmannFord(0);

    return 0;
}
