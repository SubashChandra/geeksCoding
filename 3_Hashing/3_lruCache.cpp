//implementation of lruCache using circular doubly linked list nd hash map

//O(1) time per get nd put

#define CAPACITY 10 //cache capacity

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

using namespace std;

struct dllnode
{
	int key;
	int value;
	struct dllnode *pre;
	struct dllnode *next;
};

typedef struct dllnode Dllnode;
typedef Dllnode *Dllnodeptr;

struct cirdll
{
	int count;
	int capacity;
	Dllnodeptr list;
};

typedef struct cirdll Cirdll;
typedef Cirdll *Cirdllptr;

Dllnodeptr newnode()
{
	Dllnodeptr temp = (Dllnodeptr)malloc(sizeof(Dllnode));
	return temp;
}



//insert at the end of a circular doubly linked list
Dllnodeptr insert(Dllnodeptr *start, int data) //return address of the newly created node
{
	Dllnodeptr last;
	Dllnodeptr temp = newnode();
	temp->key=data;
	temp->value=data;
	temp->pre=temp;
	temp->next=temp;

	if(*start==NULL) 
		*start=temp;

	else //insert at the end nd update pointers
	{
		last=(*start)->pre; //get last node

		last->next=temp;
		temp->pre=last;

		temp->next=*start;
		(*start)->pre=temp;
	}

	return temp;
}

//delete from teh beginning of a circular doubly linked list
int deletenode(Dllnodeptr *start) //return key of the deleted node
{
	Dllnodeptr temp,last;
	int key;

	if(*start==NULL)
	{
		printf("empty cdll\n");
		return -1;
	}
	else if((*start)->next==*start)
	{
		temp=*start;
		key=temp->key;
		*start=NULL;
		free(temp);
		return key;
	}

	//delete first node
	last=(*start)->pre;

	temp=*start;
	key=temp->key;
	*start=(*start)->next;
	(*start)->pre=last;
	last->next=*start;

	free(temp);
	return key;

}


//print dll
void printcdll(Dllnodeptr start)
{
	if(start==NULL)
	{
		printf("empty cdll\n");
		return;
	}

	printf("**cir dll**\n");
	Dllnodeptr head=start;
	do
	{
		printf("<-%d->",start->key);
		start=start->next;
	}while(start!=head);
	printf("%d\n",start->key); //printing start node to point that this is indeed a circular dll

}

//put into lru cache
void put(Cirdllptr *start, int data, map<int,Dllnodeptr> *m1)
{
	
	Dllnodeptr nodeAddress;
	int key;
	//two cases here if Cirdll is full nd not full
	if((*start)->count == (*start)->capacity) //if full, delete least recently used element
	{
		key = deletenode(&((*start)->list));
		if(key!=-1) //update map
		{
			printf("deleting %d from cache\n",key);
			(*m1).erase(key);
			(*start)->count--; //decrement count
		}
		else
		{
			printf("error:not inserted\n");
			return;
		}
	}

	//now insert the new data

	nodeAddress = insert(&((*start)->list),data);
	(*start)->count++;
	(*m1).insert(pair<int,Dllnodeptr>(data,nodeAddress));
}


//move the node with address tp the start of the linked lisr
void move(Cirdllptr *start, Dllnodeptr node)
{
	Dllnodeptr head, last;

	head = (*start)->list;
	if(head==node) //if the node accessed is teh first node , no need to move
	{
		return;
	}
	else
	{
		//update nodes that are next nd pre to cur
		node->pre->next=node->next;
		node->next->pre=node->pre;

		//now insert this at the start
		last=head->pre; //save last

		node->next=head;
		head->pre=node;
		last->next=node;
		node->pre=last;

		(*start)->list=node; //update list head in cdll
	}
}


//get data from lru
int get(Cirdllptr *start, int data, map<int,Dllnodeptr> m1)
{
	//may contain or may not contain in cache return -1 if not present, else return value
	if(m1.find(data)==m1.end()) //if not present in cache
	{
		printf("key %d doesn't exist in cache\n",data);
		return -1;
	}

	//now move the linked list node to the beginning of the cdll
	move(start,(m1.find(data))->second);

	return (*start)->list->value; //cause it has been moved to the head
}

	
int main()
{
	map<int,Dllnodeptr>m1; //map with key nd value where value is teh address of dllnode

	Cirdllptr start = (Cirdllptr)malloc(sizeof(Cirdll));
	start->count=0;
	start->capacity=CAPACITY;
	start->list=NULL;

	printcdll(start->list);

	int choice,data;
	printf("enter 1 to put element in catche, 2 to get element from cache, 3 to display cache nd -1 to exit:  ");
	scanf("%d",&choice);

	while(choice!=-1)
	{
		switch(choice)
		{
			case 1: //put inserts into the cache md if the cache is full, lru element is deleted to make room
				printf("enter data to insert: \n");
				scanf("%d",&data);
				put(&start,data,&m1); //nodeAddress has the address of the newly created node

				printf("list after put:\n");
				printcdll(start->list);
				break;

			case 2: //makes the requested element be brought to the start of the cdll
				printf("enter data to get: \n");
				scanf("%d",&data);
				printf("value is %d\n",get(&start,data,m1));

				printf("list after get:\n");
				printcdll(start->list);
				break;

			case 3: 
				printf("cache state:\n");
				printcdll(start->list);
				break;
			
		}
		printf("enter 1 to put element in catche, 2 to get element from cache, 3 to display cache nd -1 to exit:  ");
		scanf("%d",&choice);
	}

	return 0;
}
	

	
