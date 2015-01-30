//print the n th node from the end
//using two pointers

//O(n) time


#include<iostream>
#include<cstdio>
#include<cstdlib>


using namespace std;

struct node
{
	int data;
	struct node *nextptr;
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
			startptr = startptr->nextptr;
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
		newnode->nextptr = NULL;

		while(currentptr != NULL)//iterate to the end
		{
			preptr = currentptr;
			currentptr = currentptr->nextptr;
		}

		if(preptr == NULL)//if list is empty
		{
			*startptr = newnode;
		}
		else //else insert at the end of the list
		{
			preptr->nextptr = newnode;
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
		*startptr = (*startptr)->nextptr;
		printf("%d deleted\n",temp->data);
		free(temp);
	}
}


//print nth node from the end
void nthNode(Listnodeptr start, int n)
{
	if(start==NULL)
		return;

	Listnodeptr first,second;
	first=second=start;

	while(n>0 && first!=NULL) //iterate the first pointer n times
	{
		first=first->nextptr;
		n--;
	}

	if(n>0) //if n>0, there are less than n nodes in list
	{
		printf("out of range\n");
		return;
	}

	while(first!=NULL) //now itearate both until end of list is rwched
	{
		first=first->nextptr;
		second=second->nextptr;
	}

	printf("%d\n",second->data);
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
	int x;
	scanf("%d",&x);

	nthNode(startptr,x);

	return 0;
}


