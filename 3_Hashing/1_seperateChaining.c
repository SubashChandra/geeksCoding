//implement seperate chaining 

#define LOAD_FACTOR 3 //per bucket max

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

typedef struct hashTableNode HashTableNode;
typedef HashTableNode *HashTableNodeptr;

struct hashTable
{
	int tsize;
	int count;  //no of elements in table
	struct hashTableNode **table; //an array of hashTableNode pointers
};
typedef struct hashTable HashTable;
typedef HashTable *HashTableptr;


int insert(HashTableptr h, int data);
void print(HashTableptr h);


//create a emoty hash table
struct hashTable* create(int size)
{
	HashTableptr h;
	h= (HashTableptr)malloc(sizeof(HashTable));
	if(h==NULL)
		return NULL;

	h->tsize=size/LOAD_FACTOR; //
	h->count=0;
	h->table = (HashTableNodeptr *)malloc(sizeof(HashTableNodeptr)*(h->tsize)); //create a hashTable of size h->tsize

	if(h->table==NULL)
	{
		printf("memory error\n");
		return NULL;
	}
	int i;
	printf("table size %d**\n",h->tsize);
	for(i=0;i<h->tsize;i++) //nd set each hashTableNode next to NULL & bcount to 0
	{
		h->table[i]=(HashTableNodeptr)malloc(sizeof(HashTableNode));
		h->table[i]->next=NULL;
		h->table[i]->bcount=0;
	}

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

HashTableptr rehash(HashTableptr h)
{

	int oldTableSize = h->tsize*LOAD_FACTOR; //old table size = no of buckets * LOAD_FACTOR

	Listnodeptr temp;
	int i;
	HashTableptr newTable = (HashTableptr)malloc(sizeof(HashTable));
	newTable->count = 0;
	newTable->tsize = (oldTableSize*2)/LOAD_FACTOR; //no of buckets in new table is (2* size of old table)/LOAD_FACTOR
	newTable->table = (HashTableNodeptr *)malloc(sizeof(HashTableNodeptr)*newTable->tsize);

	for(i=0;i<newTable->tsize;i++)
	{
		newTable->table[i]=(HashTableNodeptr)malloc(sizeof(HashTableNode));
		newTable->table[i]->bcount=0;
		newTable->table[i]->next=NULL;
	}
	
	//now iterate over all teh old hashtable elemenst nd insert them in the newtable
	for(i=0;i<h->tsize;i++)
	{
		temp=h->table[i]->next;
		while(temp!=NULL)
		{
			insert(newTable,temp->data);
			temp=temp->next;
		}
	}
	
	//delete odl table nd point h to new table
	h=newTable;
	printf("rehashed table\n");
	return h;
}



//insert into the hash table
int insert(HashTableptr h, int data)
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

	return 1;
}
	


//delete from teh hash table
int delete(HashTableptr h, int data)
{
	if(h->count==0)
		return 0;
	int index;
	Listnodeptr temp, pre;
	index= hash(data, h->tsize);
	
	temp=h->table[index]->next;
	pre=NULL;

	while(temp!=NULL)
	{
		if(temp->data==data) //if foudn delete nd return 1, else 0
		{
			if(pre==NULL)
				h->table[index]->next=temp->next;
			else
				pre->next=temp->next;
			free(temp);

			h->table[index]->bcount--;
			h->count--;
			return 1;
		}
		else
			pre=temp;
			temp=temp->next;

	}
	return 0;
}
		


//print hash table

void print(HashTableptr h)
{
	if(h->count==0)
	{
		printf("table is empty\n");
		return;
	}

	Listnodeptr cur;
	printf("table size: %d buckets: %d\n",h->count,h->tsize);

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

	HashTableptr h = create(size);
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
		//rehash check
		if((h->count/h->tsize) >= LOAD_FACTOR)
		{
			h=rehash(h);
			print(h);
		}
	}

	while(1)
	{
		printf("enter data to delete: ");
		scanf("%d",&data);
		if(data==-1)
			break;
		delete(h,data);
		print(h);
	}



	return 0;
}
		
	

	
