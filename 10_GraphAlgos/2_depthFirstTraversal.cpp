//depth first traversal uisng adjacency lists


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
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&u,&v);
		g->adj[u].push_back(v);
	}


	printf("now display graph:\n");

	list<int>::iterator it;
	for(i=0;i<v;i++)
	{
		if(g->adj[i].size()==0)
			continue;
		printf("%d ->",i);
		for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
			printf("%d ",*it);
		printf("\n");
	}
	return 0;
}
			
	


