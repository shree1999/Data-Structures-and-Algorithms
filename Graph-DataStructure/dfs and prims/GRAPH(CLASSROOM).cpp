#include<iostream>
#include<list>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;

int visited[100];
//for(int i=0;i<100;i++)
//{visited[i]=-1;
//}
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
					temp=newnode;//temp=temp->next
				}
			}
		}
	}
}


void ListGraph::display()
{
	cout<<"\n Adjacancy list for the graph is";
	GraphNode *temp;
	for(int i=0;i<n;i++)
	{cout<<"vertex "<<i<<endl;
		//cout<<list[i]<<" --> ";
		temp=list[i];
		while(temp!=NULL)
		{
			cout<<temp->vertex<<" --> ";
			temp=temp->next;
		}
		cout<<"NULL"<<endl<<endl;
		
	}
}

void ListGraph::recursiveDFS(int v)
{GraphNode *temp;
	visited[v]=1;
	cout<<v<<" --> ";
	temp=list[v];
	while(temp!=NULL)
	{
		if(visited[temp->vertex] !=1)
		{
			recursiveDFS(temp->vertex);
		}
		temp=temp->next;
	}
}

void ListGraph::DFSstack(int v)
{
	GraphNode *temp;
	bool visit[100];
	stack<int> s;
	int w;
	for(int i=0;i<n;i++)
	{
		visit[i]=false;
	}
	visit[v]=true;
	
	
		
	cout<<v<<"--> ";
	s.push(v);
	while(!s.empty())
	{
	
	temp=list[v];
	//if(s.empty())break;
	while(temp!=NULL)
	{w=temp->vertex;
		if(visit[w]==false)
		{
			visit[w]=true;
			cout<<w<<" --> ";
			s.push(w);
			v=w;
		}
		temp=temp->next;
	}
	v=s.top();
	s.pop();
	
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
