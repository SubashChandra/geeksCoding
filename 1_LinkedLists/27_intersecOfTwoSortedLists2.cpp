//intersec of two sorted lists without modifyig the original lists
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


Listnodeptr intersec(Listnodeptr l1, Listnodeptr l2)
{
	if(l1==NULL || l2==NULL)
		return NULL;
	Listnodeptr newnode;
	
	if(l1->data == l2->data) //if match in data
	{
		newnode=(Listnodeptr)malloc(sizeof(Listnode));
		newnode->data=l1->data;
		newnode->next=intersec(l1->next,l2->next);

		return newnode;
	}

	//else go recursive
	else if(l1->data < l2->data)
		return intersec(l1->next,l2);

	else
		return intersec(l1,l2->next);

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

	Listnodeptr list3=intersec(list1,list2);
	printList(list3);





	return 0;
}

