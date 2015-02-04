//same code but without typedef
//implement seperate chaining 

#define LOAD_FACTOR 20 //per bucket max

#include<stdio.h>
#include<stdlib.h>


struct listnode
{
	int data;
	struct listnode *next;
};
typedef struct listnode Listnode;
typedef Listnode *Listnodeptr;


struct hashTableNode
{
	int bcount; //no of elements in the bucket
	struct listnode *next;
};


struct hashTable
{
	int tsize;
	int count;  //no of elements in table
	struct hashTableNode **table; //an array of hashTableNode pointers
};


//create a emoty hash table
struct hashTable* create(int size)
{
	struct hashTable * h;
	h= (struct hashTable *)malloc(sizeof(struct hashTable));
	if(h==NULL)
		return NULL;

	printf("check1\n");
	h->tsize=size/LOAD_FACTOR; //
	h->count=0;
	h->table = (struct hashTableNode**)malloc(sizeof(struct hashTableNode*)*(h->tsize)); //create a hashTable of size h->tsize
	printf("check2\n");

	if(h->table==NULL)
	{
		printf("memory error\n");
		return NULL;
	}
	int i;
	printf("table size %d**\n",h->tsize);
	for(i=0;i<h->tsize;i++) //nd set each hashTableNode next to NULL & bcount to 0
	{
		h->table[i]=(struct hashTableNode *)malloc(sizeof(struct hashTableNode));
		h->table[i]->next=NULL;
		h->table[i]->bcount=0;
	}
	printf("check3\n");

	return h;
}
	

//create a hash function
int hash(int data, int tsize) //returns values from 0 to tszie-1
{
	return data%tsize;
}


//search for an element in the hash table
int search(struct hashTable *h,int data)
{
	Listnodeptr temp;

	temp= h->table[hash(data,h->tsize)]->next;

	while(temp!=NULL)
	{
		if(temp->data==data)
			return 1;
		temp=temp->next;
	}
	return 0;
}


//insert into the hash table
int insert(struct hashTable *h, int data)
{
	int index;
	Listnodeptr temp, next;

	if(search(h,data)==1) //duplicate
		return 0;
	
	Listnodeptr newnode;
	index=hash(data,h->tsize);

	temp=h->table[index]->next;
	newnode=(Listnodeptr)malloc(sizeof(Listnode));
	if(newnode==NULL)
	{
		printf("out of space\n");
		return -1;
	}

	newnode->data= data;
	newnode->next=temp; //insert at the begining of the list at table[index]
	h->table[index]->next=newnode;
	h->table[index]->bcount++; //incremenet no fo elments in that bucket
	h->count++; //no of elements in the table

	//rehash check
	//if(h->count/h->tsize > LOAD_FACTOR)
	//	rehash(h);
	return 1;
}
	


//delete from teh hash table
int delete(struct hashTable *h, int data)
{
	int index;
	Listnodeptr temp, pre;
	index= hash(data, h->tsize);
	
	temp=h->table[index]->next;
	pre=NULL;

	while(temp!=NULL)
	{
		if(temp->data==data) //if foudn delete nd return 1, else 0
		{
			if(pre!=NULL)
				pre->next=temp->next;
			free(temp);

			h->table[index]->next=NULL;
			h->table[index]->bcount--;
			h->count--;
			return 1;
		}

	}
	return 0;
}
		


//print hash table

void print(struct hashTable *h)
{
	if(h->count==0)
	{
		printf("table is empty\n");
		return;
	}

	Listnodeptr cur;
	printf("table size: %d\n",h->count);

	int i;
	for(i=0;i<h->tsize;i++) //iterate over the table
	{
		cur=h->table[i]->next;
		printf("key is: %d, size is %d nd contains :   ",i,h->table[i]->bcount);
		while(cur!=NULL) //print each bucket
		{
			printf("%d->",cur->data);
			cur=cur->next;
		}
		printf("NULL\n");
	}
}



int main()
{
	int size;
	printf("enter hash table size: ");
	scanf("%d",&size);

	struct hashTable *h = create(size);
	printf("created hash table of size %d\n",h->tsize);
	print(h);

	int data;
	
	while(1)
	{
		printf("enter data to insert nd -1 to break\n");
		scanf("%d",&data);
		if(data==-1)
			break;
		insert(h,data);
		print(h);
	}

	return 0;
}
		
	

	
