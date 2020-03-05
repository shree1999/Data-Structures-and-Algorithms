#include <iostream>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
	int val;
	Node* next;
};

// Data structure to store graph edges
struct Edge {
	int src, dest;
};

class Graph
{
	int N;  // number of nodes in the graph

	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;
		newNode->next = head;

		return newNode;
	}


public:

	// An array of pointers to Node to represent adjacency list
	Node **head;
	Graph(Edge edges[], int n, int N) {
		head = new Node*[N]();
		this->N = N;

		// initialize head pointer for all vertices
		for (int i = 0; i < N; i++)
			head[i] = NULL;

		// add edges to the directed graph
		for (int i = 0; i < n; i++) {
			int src = edges[i].src;
			int dest = edges[i].dest;
			Node* newNode = getAdjListNode(dest, head[src]); // inserting at the beginning
			head[src] = newNode;
		}
	}
};

// print all neighboring vertices of given vertex
void printList(Node* ptr) {
	while (ptr != nullptr) {
		cout << " -> " << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
int main() {
	// array of graph edges as per above diagram.
	Edge edges[] = {
		// pair (src, dest) represents edge from src to dest
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int N = 6;
	int n = sizeof(edges)/sizeof(edges[0]);

	Graph graph(edges, n, N);
	for (int i = 0; i < N; i++) {
		cout << i << " --";
		printList(graph.head[i]);
	}

	return 0;
}
