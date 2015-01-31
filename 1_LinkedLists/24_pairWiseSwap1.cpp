//do a pair wise swap on the linked list
//iterative approach

//O(n) time
//O(1) space

#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *arbitptr;
};

typedef struct node Listnode;
typedef Listnode *Listnodeptr;

void printList(Listnodeptr startptr)
{
	if(startptr)
	{
		while(startptr)
		{
			printf("%d-->",startptr->data);
			startptr = startptr->next;
		}
		printf("NULL\n\n");
	}
	else
	{
		printf("list is empty\n");
	}
}

void insert(Listnodeptr *startptr, int data)
{
	Listnodeptr newnode = (Listnode *)malloc(sizeof(Listnode));
	Listnodeptr preptr=NULL;
	Listnodeptr currentptr = *startptr;
	if(newnode)
	{
		newnode->data = data;
		newnode->next = NULL;

		while(currentptr != NULL)//iterate to the end
		{
			preptr = currentptr;
			currentptr = currentptr->next;
		}

		if(preptr == NULL)//if list is empty
		{
			*startptr = newnode;
		}
		else //else insert at the end of the list
		{
			preptr->next = newnode;
		}
	}
	else
	{
		printf("error: out of memory\n");
	}
}

//delete func

void deleteList(Listnodeptr *startptr)
{
	Listnodeptr temp;

	while(*startptr != NULL)
	{
		temp= *startptr;
		*startptr = (*startptr)->next;
		printf("%d deleted\n",temp->data);
		free(temp);
	}
}


void pairWiseSwap(Listnodeptr *start)
{
	if(*start==NULL || (*start)->next==NULL)
		return;

	Listnodeptr third,second,cur;
	cur=*start;
	*start=(*start)->next; //set the head of list

	while(cur!=NULL && cur->next!=NULL) //only if there are  2 nodes
	{
		third=cur->next->next; 
		second=cur->next; 
		second->next=cur;

		if(third && third->next) //if fourth node is not null, set next of current to forth
			cur->next=third->next;
		else //if forth is null, set necxt of current to third
			cur->next=third;

		cur=third;

	}
}


int main()
{
	Listnodeptr startptr = NULL;
	int n, data, i,nValue;
	int hasLoop = 0;//false

	printf("enter the no of elements in the list: ");
	scanf("%d",&n);

	printf("enter all the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(&startptr,data);
	}


	printList(startptr);
	pairWiseSwap(&startptr);
	printList(startptr);


	return 0;
}

