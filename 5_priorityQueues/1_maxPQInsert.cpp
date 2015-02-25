//insert elements into max priority queue
//O(logn) time
//O(1) space


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct heap
{
	int *array;
	int count;
	int capacity;
};

typedef struct heap Heap;
typedef Heap *Heapptr;

Heapptr create(int capacity)
{
	Heapptr h = (Heapptr)malloc(sizeof(Heap));
	h->array=(int*)malloc(sizeof(int)*capacity);
	h->capacity=capacity;
	h->count=0;

	return h;
}

//print max pq
void printHeap(Heapptr h)
{
	if(h->count ==0)
	{
		printf("heap is empty\n");
		return;
	}
	int i;

	for(i=0;i<h->count;i++)
		printf("%d ",h->array[i]);
	printf("\n");
}

//resize priority queue (double capacity)
Heapptr resize(Heapptr h)
{
	int *oldArray=h->array;
	h->array=(int *)malloc(sizeof(int)*h->capacity*2);

	int i;
	//copy elements
	for(i=0;i<h->capacity;i++)
		h->array[i]=oldArray[i];

	h->capacity*=2;

	free(oldArray);

	return h;
}


//insert into max pririty queue
void insert(Heapptr *h, int data)
{
	if((*h)->capacity==(*h)->count)
		*h=resize(*h);

	(*h)->count++;
	int i=(*h)->count-1;

	//percolate up
	while(i>0 && data>(*h)->array[(i-1)/2])
	{
		(*h)->array[i]=(*h)->array[(i-1)/2];
		i=(i-1)/2;
	}
	(*h)->array[i]=data;
}


int main()
{
	int capacity,i;

	scanf("%d",&capacity);
	Heapptr h = create(capacity);

	i=0;
	int data;
	while(i<capacity)
	{
		scanf("%d",&data);
		insert(&h,data);
		printHeap(h);
	}

	return 0;
}
	


