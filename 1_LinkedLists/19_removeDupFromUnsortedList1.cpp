//remove duplicates from a unsorted list
//naive approach using two loops
//O(n*n) time
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

//given an unsorted linked list
void removeDuplicates(Listnodeptr start)
{
	Listnodeptr temp,l1,l2;
	l1=start;

	while(l1!=NULL && l1->next!=NULL)
	{
		l2=l1; //set l2 to l1
		while(l2->next!=NULL) 
		{
			if(l1->data == l2->next->data) //if l2 of next == l1
			{
				temp=l2->next;
				l2->next=l2->next->next;
				free(temp);
			}
			else //else iterate l1 forward
				l2=l2->next;
		}
		l1=l1->next;
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
	removeDuplicates(startptr);
	printList(startptr);



	return 0;
}

