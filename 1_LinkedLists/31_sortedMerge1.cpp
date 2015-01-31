//given two sorted linked lists, sorted merge them
//iterative
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
void sortedMerge(Listnodeptr *result, Listnodeptr l1,Listnodeptr l2)
{
	if(l1==NULL)
	{
		*result=l2;
		return;
	}
	else if(l2==NULL)
	{
		*result=l1;
		return;
	}

	Listnodeptr cur=NULL;

	while(l1!=NULL && l2!=NULL) //while both are non empty
	{
		if(l1->data <= l2->data) //insert from ist1
		{
			if(*result==NULL)
			{
				*result=l1;
				cur=l1;
			}
			else
			{
				cur->next=l1;
				cur=l1;
			}
			l1=l1->next;
		}
		else //else from list2
		{
			if(*result==NULL)
			{
				*result=l2;
				cur=l2;
			}
			else
			{
				cur->next=l2;
				cur=l2;
			}
			l2=l2->next;
		}
	}

	if(l1!=NULL) //if list1 is longer
		cur->next=l1;
	else if(l2!=NULL) //if list 2 is longer
		cur->next=l2;
	else //if both are of equal length
		cur->next=NULL;
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
	sortedMerge(&result,list1,list2);


	printf("merged list******\n");
	printList(result);


	return 0;
}

