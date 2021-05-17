#include<iostream>
#include<list>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;
//visited array to keep track of the elements which we visited
//declared as global
int visited[100];

//each graphnode object will have following properties
class GraphNode
{
	private:
		
	public:
		int vertex;
		GraphNode * next;
		GraphNode(int n=0)
		{
			vertex=n;
			next=NULL;
		}
};

class ListGraph :public GraphNode
{
	GraphNode * list[20];//Adjacency List initialisation
	int n;
	
	public:
		ListGraph(int nov)
		{
			n=nov;
			for(int i=0;i<n;i++)
			{
				list[i]=NULL;//initialising all the adjacency list elements to NULL
			}
		}
		void create();
		void display();
		void recursiveDFS(int v);
		void DFSstack(int v);
		void BFS(int v);
		
};


//creating and inserting elements in our adjacency list

void ListGraph::create()
{
	GraphNode *temp,*newnode;
	int i,j,x;
	cout<<"\n 1 if there is edge";
	cout<<"\n 0 if no edge";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"\n If there is edge between "<<i<<" vertice and "<<j<<" vertice  ";
			cin>>x;
			
			if(x==1)
			{newnode=new GraphNode(j);
				if(list[i]==NULL)
				{
					list[i]=temp=newnode;
				}
				else
				{
					temp->next=newnode;
					temp=newnode;
					//Alternate staement
					//temp=temp->next
				}
			}
		}
	}
}

//displaying elements in our adjacency list

void ListGraph::display()
{
	cout<<"\n Adjacancy list for the graph is";
	GraphNode *temp;
	for(int i=0;i<n;i++)
	{cout<<"vertex "<<i<<endl;
		temp=list[i];
		while(temp!=NULL)
		{
			cout<<temp->vertex<<" --> ";
			temp=temp->next;
		}
		cout<<"NULL"<<endl<<endl;
		
	}
}

//DFS function using recursion
void ListGraph::recursiveDFS(int v)
{GraphNode *temp;
	visited[v]=1;       //mark element/node  as visited
	cout<<v<<" --> ";	//print node
	temp=list[v];		//assign head pointer as temp
	while(temp!=NULL)		//traverse throught linked list till it is empty
	{
		if(visited[temp->vertex] !=1)//call recursive function on node if it is not visited
		{
			recursiveDFS(temp->vertex);
		}
		temp=temp->next;
	}
}

//DFS function using Stack

void ListGraph::DFSstack(int v)
{
	GraphNode *temp;
	bool visit[100];
	stack<int> s;
	int w;
	for(int i=0;i<n;i++)
	{
		visit[i]=false;		//mark each node as unvissited
	}
	visit[v]=true;		//mark 1st node visited
	
	
		
	cout<<v<<"--> ";
	s.push(v);			//push 1 st node on stack
	while(!s.empty())	
	{
	
	temp=list[v];		
	while(temp!=NULL)
	{w=temp->vertex;
		if(visit[w]==false)
		{
			visit[w]=true;
			cout<<w<<" --> ";	//pick a neighbour of vertex and add in stack
			s.push(w);
			v=w;
		}
		temp=temp->next;	
	}
	v=s.top();	//pick up topmost element of stack and repeat
	s.pop();	//remove element afterwards
	
	}
	
}


void ListGraph::BFS(int v)
{
	bool visit[100];
	queue<int> q;
	GraphNode * temp;
	for(int i=0;i<n;i++)
	{
		visit[i]=false;
	}
	q.push(v);
	visit[v]=true;
	cout<<v<<" --> ";
	while(!q.empty())
	{
		temp=list[v];
		while(temp!=NULL)
		{
			if(!visit[temp->vertex])
			{
				visit[temp->vertex]=true;
				cout<<temp->vertex<<" --> ";
				q.push(temp->vertex);
			}
		}
		v=q.front();
		q.pop();
		
	}
	
}



main()
{
int n;
cout<<"\n How many vertices ";
cin>>n;
	ListGraph g(n);
	g.create();
	g.display();
	cout<<"\n recursive DFS\n\n";
	g.recursiveDFS(0);
}
