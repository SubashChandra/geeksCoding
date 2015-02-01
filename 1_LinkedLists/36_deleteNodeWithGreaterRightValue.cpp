//given a linked list, delete a node if it has a greater value to its right
//reverse list, track max, delete next node if its less than max, else max=nextnode

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


Listnodeptr reverse(Listnodeptr start)
{
	if(start==NULL || start->next==NULL)
		return start;


	Listnodeptr second,rest;

	second=start->next;
	start->next=NULL;
	rest=reverse(second);
	second->next=start;;

	return rest;
}



//deletes a node if it has a greater value to its right

void func(Listnodeptr *start)
{
	if(*start==NULL || (*start)->next==NULL)
		return;

	Listnodeptr cur=*start;


	cur=reverse(cur);

	Listnodeptr temp,head;
	int max=cur->data;

	head=cur;//save the poiner to head
	while(cur->next!=NULL)
	{
		if(cur->next->data < max) //delete cur->next
		{
			temp=cur->next;
			cur->next=temp->next;
			free(temp);
		}
		else //move forward
		{
			cur=cur->next;
			max=cur->data;
		}
	}

	*start = reverse(head); //reverse list again
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

	func(&startptr);

	printList(startptr);


	return 0;
}

