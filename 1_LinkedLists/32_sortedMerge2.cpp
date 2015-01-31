//given two sorted linked lists, sorted merge them
//recursive
//O(m+n) time


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

//iterative
Listnodeptr sortedMerge( Listnodeptr l1,Listnodeptr l2)
{
	//if one is null return another
	if(l1==NULL)
		return l2;
	else if(l2==NULL)
		return l1;
	Listnodeptr result=NULL;

	//else compare lists nd go recursive appropriately
	if(l1->data <= l2->data)
	{
		result=l1;
		result->next=sortedMerge(l1->next,l2);
	}
	else
	{
		result=l2;
		result->next=sortedMerge(l1,l2->next);
	}
	return result;
}

	
				


int main()
{
	Listnodeptr list1 = NULL;
	Listnodeptr list2 = NULL;
	int n1,n2, data, i,nValue;

	printf("enter the no of elements in the list1: ");
	scanf("%d",&n1);

	printf("enter all the elements: ");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&data);
		insert(&list1,data);
	}

	printList(list1);

	printf("enter the no of elements in the list2: ");
	scanf("%d",&n2);

	printf("enter all the elements: ");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&data);
		insert(&list2,data);
	}

	printList(list2);

	Listnodeptr result=NULL;
	result = sortedMerge(list1,list2);


	printf("merged list******\n");
	printList(result);


	return 0;
}

