//huffman coding
//O(nlogn) time


#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


//huffman tree node
struct heapnode
{
	char data;
	int freq;
	struct heapnode *left;
	struct heapnode *right;
};

typedef struct heapnode Heapnode;
typedef Heapnode *Heapnodeptr;


//min heap (collection of huffman nodes)
struct minheap
{
	int size;
	int capacity;
	Heapnodeptr *array; //array of heapnode pointers
};

typedef struct minheap Minheap;
typedef Minheap *Minheapptr;


//create new heapnode
Heapnodeptr newnode(char data, int freq)
{
	Heapnodeptr temp = (Heapnodeptr)malloc(sizeof(Heapnode));
	temp->data=data;
	temp->freq=freq;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

//create new minheap

Minheapptr createMinHeap(int capacity)
{
	Minheapptr minHeap=(Minheapptr)malloc(sizeof(Minheap));
	minHeap->size=0;
	minHeap->capacity=capacity;
	minHeap->array = (Heapnodeptr*)malloc(sizeof(Heapnodeptr)*capacity);

	return minHeap;
}


void swapNodes(Heapnodeptr *a, Heapnodeptr *b)
{
	Heapnodeptr temp =*a;
	*a=*b;
	*b=temp;
}


//minHeapify function (percolate down)
void minheapify(Minheapptr minHeap, int index)
{
	int smallest=index;
	int left= 2*index+1;
	int right=2*index+2;

	if(left<minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
	{
		smallest=left;
	}

	if(right<minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
	{
		smallest=right;
	}

	if(smallest!=index)
	{
		swapNodes(&minHeap->array[smallest],&minHeap->array[index]);
		minheapify(minHeap,smallest);
	}
}
	

//check if size of heap is 1
int isSizeOne(Minheapptr minHeap)
{
	return minHeap->size==1;
}


//ectract min value from heap
Heapnodeptr extractMin(Minheapptr minHeap)
{
	Heapnodeptr temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	minHeap->size--;

	minheapify(minHeap,0);

	return temp;
}

//insert node into minHeap (percolate up)
void insert(Minheapptr minHeap, Heapnodeptr node)
{
	(minHeap)->size++;
	int i=(minHeap)->size-1;

	while(i>0 && node->freq < (minHeap)->array[(i-1)/2]->freq)
	{
		(minHeap)->array[i]=(minHeap)->array[(i-1)/2];
		i=(i-1)/2;
	}
	(minHeap)->array[i]=node;
}

//standard func to build minHeap, will percolate down till the penultimate level, so the result is minHeap
void buildMinHeap(Minheapptr minHeap)
{
	int n=minHeap->size-1;

	int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		minheapify(minHeap,i);
	}
}


void printArray(int arr[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}



int isLeaf(Heapnodeptr node)
{
	return node->left==NULL && node->right==NULL;
}

Minheapptr createNdBuildMinHeap(char data[], int freq[], int size)
{
	Minheapptr minHeap = createMinHeap(size);
	int i;
	for(i=0;i<size;i++)
	{
		minHeap->array[i]=newnode(data[i],freq[i]);
	}
	minHeap->size=size;
	buildMinHeap(minHeap);

	return minHeap;
}


//build huffman tree
Heapnodeptr buildHuffmanTree(char data[], int freq[], int size)
{
	Heapnodeptr left, right, top;

	Minheapptr minHeap = createNdBuildMinHeap(data,freq,size);
	

	//itearate while szie is not 1

	while(minHeap->size!=1)
	{
		left=extractMin(minHeap);
		right=extractMin(minHeap);

		top=newnode('#',left->freq+right->freq);
		top->left=left;
		top->right=right;
		insert(minHeap,top);
	}

	return extractMin(minHeap);
}

//print huffman codes from the root of the huffman tree
void printCodes(Heapnodeptr root, int arr[], int top)
{
	//assig 0 to left nd recur
	if(root->left)
	{
		arr[top]=0;
		printCodes(root->left,arr,top+1);
	}

	//same to right
	if(root->right)
	{
		arr[top]=1;
		printCodes(root->right,arr,top+1);
	}

	if(isLeaf(root))
	{
		printf("%c: ",root->data);
		printArray(arr,top);

	}

}

int max(int a,int b)
{
	return a>b?a:b;
}

int height(Heapnodeptr root)
{
	if(root==NULL)
		return 0;
	
	return 1+max(height(root->left),height(root->right));
}


void huffmanCodes(char data[], int freq[], int n)
{
	Heapnodeptr root=buildHuffmanTree(data,freq,n);
	int h=height(root);
	
	int arr[h];
	printCodes(root, arr,0);
}


int main()
{
	int n;
	cin>>n;
	char data[n];
	int freq[n];

	int i;
	scanf("%s",data);
	for(i=0;i<n;i++)
		cin>>freq[i];

	huffmanCodes(data,freq,n);
	
	return 0;
}







