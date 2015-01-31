//given a linked list nd k, reverse every k set of nodes
//recursive

//O(n) time

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

Listnodeptr kWiseReverse(Listnodeptr start, int k)
{
	if(start==NULL || start->next==NULL)
		return start;

	Listnodeptr first,pre,next;
	int count=k;
	first=start; //save the head of the list
	pre=NULL;

	while(count>0 && start!=NULL) //while list is not empty, run loop k times
	{
		next=start->next;
		start->next=pre;

		pre=start;
		start=next;
		count--;
	}

	//pre here will hold the head of teh reversed set
	if(start!=NULL) //if list is not empty, go recursive nd append it to the tail which is now head
		first->next=kWiseReverse(start,k);

	return pre;
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
	int k;
	scanf("%d",&k);
	startptr=kWiseReverse(startptr,k);
	printList(startptr);


	return 0;
}

