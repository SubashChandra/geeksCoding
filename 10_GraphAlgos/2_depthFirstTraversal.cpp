//depth first traversal uisng adjacency lists

//O(v) time
//O(v+e) sapce


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

void dfsUtil(Graphptr g, int v, bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";

	//recur for all the vertices adjacent to this vertex
	list<int>::iterator it;

	for(it=g->adj[v].begin();it!=g->adj[v].end();it++) //all teh vertices adjacent to v
	{
		if(visited[*it]==0) //if not visited
		{
			dfsUtil(g,*it,visited);
		}
	}
}


void dfs(Graphptr g,int v)
{
	bool *visited=new bool[g->v];
	int i;
	for(i=0;i<g->v;i++)
		visited[i]=false;

	dfsUtil(g,v,visited);
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
	for(i=0;i<g->v;i++)
	{
		if(g->adj[i].size()==0)
			continue;
		printf("%d ->",i);
		for(it=g->adj[i].begin();it!=g->adj[i].end();it++)
			printf("%d ",*it);
		printf("\n");
	}

	printf("dfs: ");
	dfs(g,0);//dfs starting at vertex 2
	printf("\n");
	return 0;
}
			
	


