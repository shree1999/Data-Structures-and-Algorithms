/* This Program is based on graph implementation using Adjacency List
    this program focuses on directed graph and it uses STL library
*/
#include<bits/stdc++.h>
using namespace std;

// A function to add an edge in an directed graph.
void addEdge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
}

// A function to print the adjacency list representation of graph
void printGraph(vector<int> adj[], int vertices)
{
	for (int i = 0; i < vertices; i++)
	{
		cout << "\n Adjacency list of vertex: "
			<< i;
		for (auto x : adj[i])
		cout << "-> " << x;
		printf("\n");
	}
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	return 0;
}

