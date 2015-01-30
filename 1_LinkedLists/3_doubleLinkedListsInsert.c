//insert elements into a double linked list
//a variant of linked list with two pointers, left and right
//time : O(n)

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *leftptr;
	struct node *rightptr;

};

typedef struct node Listnode;
typedef  Listnode *Listnodeptr;

int listSize(Listnodeptr startptr)
{
	int size=0;
	while(startptr)
	{
		size++;
		startptr = startptr->rightptr;
	}
	return size;
}


void printList(Listnodeptr startptr)
{
	printf("NULL");
	while(startptr!=NULL)
	{
		printf("<-%d->",startptr->data);
		startptr = startptr->rightptr;
	}
	printf("NULL\n");
}

//insert elements into the double linked list
void insert(Listnodeptr *startptr, int data, int index)
{
	Listnodeptr preptr = NULL;
	Listnodeptr currentptr = *startptr;

	Listnodeptr newnode = malloc(sizeof(Listnode));
	if(newnode !=NULL) //if memory allocated
	{
		newnode->data = data;
		newnode->leftptr = NULL;
		newnode->rightptr = NULL;

		while(index!=0)//iterate till the required position is reached
		{
			preptr = currentptr;
			currentptr = currentptr->rightptr;
			index--;
		}

		if(preptr == NULL) //if index is 0
		{
			newnode->rightptr = currentptr;
			if(currentptr)//if list is not empty
			{
				currentptr->leftptr = newnode;
			}
			*startptr = newnode;
		}


		else //insert at appropriate position
		{
			preptr->rightptr = newnode;
			newnode->leftptr = preptr;

			newnode->rightptr=currentptr;
			if(currentptr!=NULL)//if end of list is not reached
			{
				currentptr->leftptr=newnode;
			}
		}
	}
}


int main()
{
	int data, choice,pos, i;

	Listnodeptr startptr = NULL;

	printf("enter 1 to insert at the beginning, 2 at the end, 3 at a position nd 4 to exit: ");
	scanf("%d", &choice);

	int size;
	while(choice !=4)
	{
		switch (choice)
		{
			case 1: //insert at the beginning
				printf("enter data to insert: ");
				scanf("%d",&data);
				insert(&startptr, data,0);
				printList(startptr);
				break;
			
			case 2: //insert at the end
				printf("enter data to inser: ");
				scanf("%d",&data);
				size = listSize(startptr);
				insert(&startptr, data, size);
				printList(startptr);
				break;

			case 3: //insert at a position
				printf("enter a position u want to insert element at: ");
				scanf("%d",&pos);
				printf("enter data to insert: ");
				scanf("%d",&data);

				size = listSize(startptr);
				if(pos>0 && pos <=size+1)
				{
					insert(&startptr, data, pos-1);
					printList(startptr);
				}
				else
				{
					printf("enter a valid position\n");
				}
				break;

				
			case 4: 
				printf("invalid choice\n");
				break;
		}//switch

		printf("enter 1 to insert at the beginning, 2 at the end, 3 at a position nd 4 to exit: ");
		scanf("%d", &choice);
	}//while


}//main
