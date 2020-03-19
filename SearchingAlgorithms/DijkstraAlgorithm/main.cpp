/* This algorithm called Dijkstra's algorithm is used to find the
   shortest distance between one node(source) and all other nodes. */

#include <iostream>
#include <cstdlib>
#include <climits>
#define V 9 // maximum number of nodes(vertices)

int minDistance(int dist[], bool visited[]) {
    int minimum = INT_MAX, min_index;

    for(int i = 0; i < V; i++) {
        if(visited[i] == false && dist[i] <= minimum) {
            minimum = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // final distances.
    bool visited[V]; // check for nodes whose shortest nodes have been identified

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // initially putting all distances to maximum values.
        visited[i] = false;
    }

    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {

        int u = minDistance(dist, visited);
        visited[u] = true;
        for(int j = 0; j < V; j++) {
            if(!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                      { 4, 0, 8, 0, 0, 0, 0, 11, 0},
                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },   // matrix representation of graph.
                      { 0, 0, 7, 0, 9, 14, 0, 0, 0},
                      { 0, 0, 0, 9, 0, 10, 0, 0, 0},   // 0 represents no edge between one node to another
                      { 0, 0, 4, 14, 10, 0, 2, 0, 0},
                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                      { 8, 11, 0, 0, 0, 0, 1, 0, 7},
                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    dijkstra(graph, 0); // 0 represents source node
    return 0;
}
