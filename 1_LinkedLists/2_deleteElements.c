//delete given data element from a linked list
//time: O(n)

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nextptr;
};

typedef struct node Listnode;
typedef Listnode *Listnodeptr;


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

//insert at an index implementation
void insert(Listnodeptr *startptr, int data, int index)
{
	Listnodeptr newptr;
	Listnodeptr preptr=NULL;
	Listnodeptr currentptr = *startptr;

	newptr = malloc(sizeof(Listnode));
	if(newptr !=NULL)
	{
		newptr->data = data;
		newptr->nextptr = NULL;

		while(index!=0)
		{
			preptr = currentptr;
			currentptr = currentptr->nextptr;
			index--;
		}

		if(preptr == NULL)
		{
			newptr->nextptr = *startptr;
			*startptr = newptr;

		}
		else
		{
			preptr->nextptr = newptr;
			newptr->nextptr = currentptr;
		}
	}
}

//delete a given data item
void delete(Listnodeptr *startptr, int data)
{
	Listnodeptr preptr = NULL;
	Listnodeptr currentptr = *startptr;
	Listnodeptr temp;
	
	if(*startptr == NULL) //if list is empty
	{
		printf("error: list is empty\n");
		return;
	}

	while(currentptr != NULL && currentptr->data != data)//traverse until data is found or end of list is reached
	{
		preptr = currentptr;
		currentptr = currentptr->nextptr;
	}

	if(preptr == NULL && currentptr->data == data) //if item is at the beginning
	{
		temp = currentptr;
		*startptr = currentptr->nextptr; //update head of list
		printf("%d deleted form list\n",temp->data);
		free(temp);
	}

	else if(currentptr == NULL) //if end of list is reached
	{
		printf("%d not in list\n",data);
		return;
	}

	else //if currentptr holds the data
	{
		temp = currentptr;
		preptr->nextptr = currentptr->nextptr;
		printf("%d deleted form list\n",temp->data);
		free(temp);
		return;
	}
}



int main()
{
	Listnodeptr startptr = NULL; //create a pointer to the start of the list
	
	int n, item,i,size;
	printf("enter no of elements to insert: ");
	scanf("%d",&n);
	printf("enter all elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d", &item);
		size = sizeofLL(startptr);	
		insert(&startptr, item,size);
	}

	printList(startptr);

	printf("enter item to delete & -1 to exit: ");
	scanf("%d",&item);
	while(item!=-1)
	{
		delete(&startptr,item);
		printList(startptr);
		printf("\nenter item to delete & -1 to exit: ");
		scanf("%d",&item);

	}

	return 0;
}


