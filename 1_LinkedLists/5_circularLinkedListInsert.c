//insert in a circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nextptr;
};

typedef struct node Listnode;
typedef Listnode *Listnodeptr;

int listSize(Listnodeptr startptr)
{
	if(startptr == NULL)
		return 0;
	Listnodeptr currentptr = startptr;

	int size=0;
	do
	{
		size++;
		currentptr = currentptr->nextptr;
	}while(currentptr != startptr);

	return size;
}


void printList(Listnodeptr startptr)
{
	if(startptr == NULL)
	{
		printf("list is empty\n");
		return;
	}

	Listnodeptr currentptr = startptr;

	do
	{
		printf("%d-->",currentptr->data);
		currentptr = currentptr->nextptr;
	}while(currentptr != startptr);
	
	printf("\n");
	return;
}

//insert data nodes at the beginning or  at the end of the list
void insert(Listnodeptr *startptr, int data, int position)
{
	Listnodeptr currentptr = *startptr;
	Listnodeptr newnode = malloc(sizeof(Listnode));

	if(newnode!=NULL)
	{

		newnode->data = data;
		newnode->nextptr = newnode;//create a self referrence

		if(*startptr == NULL)//if list is empty
		{
			*startptr = newnode;
		}


		else //insert and update head of list if necessary
		{
			while(currentptr->nextptr != *startptr)
			{
				currentptr=currentptr->nextptr;
			}
			currentptr->nextptr = newnode;
			newnode->nextptr = *startptr;
			if(position ==0) //insert at the beginning
				*startptr=newnode;

		}
	}

}

int main()
{
	Listnodeptr startptr = NULL;
	int choice, data, i,size;

	printf("enter 1 to insert at teh begining, 2 to insert at the end and 3 to exit: ");
	scanf("%d",&choice);
	while(choice!=3)
	{
		switch(choice)
		{
			case 1: 
				printf("enter the element: ");
				scanf("%d",&data);
				insert(&startptr, data,0);//0 if at the beginning
				printList(startptr);
				break;

			case 2:
				printf("enter the element: ");
				scanf("%d",&data);
				insert(&startptr, data,1);//1 if at the end
				printList(startptr);
				break;

			default:
				printf("invalid choice\n");
				break;
		}//switch

		printf("enter 1 to insert at teh begining, 2 to insert at the end and 3 to exit: ");
		scanf("%d",&choice);
	}//while

	return 0;
}//main



