//given no of vertice s nd edges, represent it as an adjacency list
//O(E) time
//O(E) space



#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<list>


using namespace std;


struct graph
{
	int v;
	list<int> *adj;
};

typedef struct graph Graph;
typedef Graph *Graphptr;


Graphptr create(int v)
{
	Graphptr g=(Graphptr)malloc(sizeof(Graph));
	g->v=v;
	g->adj = new list<int>[v];
	return g;
}


int main()
{
	int e,v;
	scanf("%d %d",&e,&v);

	Graphptr g=create(v);

	int i;
	int u;

	for(i=0;i<e;i++) //scan no of edges nd insert, ie (u,v) as push_back v to list adj[u]
	{
		scanf("%d %d",&u,&v);
		g->adj[u].push_back(v);
	}


	printf("now display graph:\n");

	list<int>::iterator it;
	for(i=0;i<g->v;i++)
	{
		printf("%d ->",i);
		for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
			printf("%d ",*it);
		printf("\n");
	}
	return 0;
}
			
	


