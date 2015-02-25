//heap sort in place, using maxheap
//rswap first element (max) with last element, decrease heap size, percolateDown(h,0) 
//comtinue till h->count ==1

//O(nlogn) time
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
	printf("heap: ");

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


//index of left child
int leftChild(Heapptr h, int i)
{
	int index=2*i+1;

	if(index>=h->count) //out of range
		return -1;

	return index;;
}

//index of right child
int rightChild(Heapptr h, int i)
{
	int index=2*i+2;

	if(index>=h->count)
		return -1;
	return index;
}

//percolate down (used when deleteTing top elemet)
void percolateDown(Heapptr *h, int i)
{
	int left,right,max,temp;
	left=leftChild(*h,i);
	right=rightChild(*h,i);

	//find max of i nd children of i
	if(left!=-1 && (*h)->array[left]>(*h)->array[i])
		max=left;
	else
		max=i;

	if(right!=-1 && (*h)->array[right]>(*h)->array[max])
		max=right;

	//swap if max!=i nd go recursive
	if(max!=i)
	{
		temp=(*h)->array[i];
		(*h)->array[i]=(*h)->array[max];
		(*h)->array[max]=temp;
		percolateDown(h,max);
	}
	
	//else i is greater than its children,so stop
	else 
		return;
}


//top element in maxHeap
int getMax(Heapptr h)
{
	if(h->count==0)
		return -1;
	return h->array[0];
}

int deleteMax(Heapptr *h)
{
	if((*h)->count==0)
		return -1;

	int data=(*h)->array[0];

	//copy lasy element to root nd percolate down
	(*h)->array[0]=(*h)->array[(*h)->count-1];
	(*h)->count--;

	percolateDown(h,0);
	return data;
}


Heapptr heapSort(Heapptr h)
{
	
	if(h->count==0 || h->count==1)
		return h;
	int temp;
	int oldSize=h->count;

	while(h->count>1) //while there are atleast 2 elements to sort
	{
		temp=h->array[0];
		h->array[0]=h->array[h->count-1]; //copy last element to root
		h->array[h->count-1] =temp; //copy max element to last
		h->count--;
		
		//now heapify
		percolateDown(&h,0);
	}
	h->count=oldSize; //restore size
	return h;
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
		if(data==-1)
			break;
		insert(&h,data);
		printHeap(h);
	}


	h=heapSort(h);
	printf("heap after sorting\n");
	printHeap(h);


	return 0;
}
	


