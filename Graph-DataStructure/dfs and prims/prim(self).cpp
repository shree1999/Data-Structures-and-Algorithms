#include<stdio.h>
#include<stdbool.h>
#include<stdio.h>
#include<iostream>

#define V 6	//6 vertices/node in graph
using namespace std;

int minKey(int key[],bool mstSet[])	//return minimum element among all elements in mstSet
{
	int min=1000,min_index;
	for(int v=0;v<V;v++)
	{
		if(mstSet[v]==false&&key[v]<min)
		{min=key[v],min_index=v;
		}
	}
	return min_index;
}

int printMST(int parent[],int graph[V][V])//print minimum spanning tree
{
	cout<<"Edge \tWeight\n";
	
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<" -"<<i<<" \t"<<graph[i][parent[i]];
	}
}


void prim(int graph[V][V])	
{
	int parent[V];
	int key[V];
	bool mstSet[V];
	
	for(int i=0;i<V;i++)		
	{
		key[i]=1000,mstSet[i]=false;
		key[0]=0;
		parent[0]=-1;
		for(int count=0;count<V-1;count++)
		{
			int u=minKey(key,mstSet);//find minimum edge cost and add in mst
			mstSet[u]=true;
			
			for(int v=0;v<V;v++)
			{
				if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
				{
					parent[v]=u,key[u]=graph[u][v];
				}
			}
		}
	}
	
	printMST(parent,graph);
}



int main()
{
	int graph[V][V]={{0,2,0,0,4},
					{2,0,8,0,0,3},
					{0,8,0,6,1,0},
					{0,0,6,0,12,0},
					{4,3,0,0,2,0}
					};
	prim(graph);
	//return 0;
}
