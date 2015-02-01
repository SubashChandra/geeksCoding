//given alinked list, reverse alt nodes nd append at teh end
//1-2-3-4-5-6-NULL becomes 1-3-5-6-4-2-NULL
//no need to reverse alt nodes, jst append alt nodes at he start of new list nd append new lost to the end of modified orig list

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



//reverse alt nodes nd append at the end
void func(Listnodeptr start)
{
	if(start==NULL || start->next==NULL || start->next->next==NULL) //2 or less nodes no change
		return;

	Listnodeptr pre,list2=NULL,second,next;

	while(start!=NULL && start->next!=NULL)	
	{
		second=start->next;
		next=second->next;

		second->next=list2; //insert node at the start of list2
		list2=second;

		start->next=next; //update next of start
		pre=start;
		start=next;
	}
	if(start!=NULL) //when odd length
	{
		pre=start;
		start=start->next;
	}

	pre->next=list2; //apeend at the end of original list
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
	func(startptr);	
	printf("modified list:\n");
	printList(startptr);

	return 0;
}

