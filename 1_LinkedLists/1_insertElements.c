//insert elemenst in a linked list either at the start, end or at an index
//O(n) average time complexity


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nextptr;
};

typedef struct node Listnode;
typedef Listnode *Listnodeptr;//create a double pointer, so Listnodeptr is a double pointer


int sizeofLL(Listnodeptr list)
{
	int size=0;
	while(list!=NULL)
	{
		list = list->nextptr;
		size++;
	}

	return size;

}
	
void printList (Listnodeptr list)
{
	while(list !=NULL)
	{
		printf("%d-->",list->data);
		list= list->nextptr;
	}
	printf("NULL\n\n");
}	

//insert elements at a given index
void insert(Listnodeptr *startptr, int data, int index)
{
	Listnodeptr newptr;
	Listnodeptr preptr=NULL;
	Listnodeptr currentptr = *startptr;

	newptr = malloc(sizeof(Listnode));
	if(newptr !=NULL)//if memory allocated
	{
		newptr->data = data;
		newptr->nextptr = NULL;

		while(index!=0)//itearate to appropriate position
		{
			preptr = currentptr;
			currentptr = currentptr->nextptr;
			index--;
		}

		if(preptr == NULL) //insert at the beginning
		{
			newptr->nextptr = *startptr;
			*startptr = newptr;//update head of teh list

		}
		else//insert between pre and currentptr
		{
			preptr->nextptr = newptr;
			newptr->nextptr = currentptr;
		}
	}
}

int main()
{
	Listnodeptr startptr = NULL;

	int choice;
	printf("enter 1 to insert at the beginning, 2 to insert at the end, 3 to insert at an index and 4 to exit: ");
	scanf("%d",&choice);

	int item, index,size;

	while(choice!=4)
	{
		switch(choice)
		{
			case 1:
				//insert an element into the linked list at the beginning
				printf("enter a number: ");
				scanf("%d",&item);
				insert(&startptr, item,0);
				printList(startptr);
				break;

			case 2:
				//insert an element at the end
				printf("enter a number: ");
				scanf("%d",&item);
				size = sizeofLL(startptr);	
				insert(&startptr, item,size);
				printList(startptr);
				break;

			case 3:
				//insert at index 
				printf("enter a position where to insert the element: ");
				scanf("%d",&index);
				printf("enter a number: ");
				scanf("%d",&item);
				size = sizeofLL(startptr);	
				if(index > 0 && index <= size+1)//position can range from 1 to (sizeOfLL)+1, where (sizeOfLL)+1 implies end of the list
				{
					insert(&startptr, item, index-1);
					printList(startptr);
				}
				else
				{
					printf("index is out of range of linked list\n enter valid index\n");
				}
				break;
			default:
				break;

		}
	
		printf("enter 1 to insert at the beginning, 2 to insert at the end, 3 to insert at an index and 4 to exit: ");
		scanf("%d",&choice);
	}
				



	return 0;
}


