//given a circular linked list, split it into half
//using two pointers slow nd fast

//O(n) time
//O(1) space


#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nextptr;
};

typedef struct node Listnode;
typedef Listnode* Listnodeptr;

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
	

	printf("NULL\n\n");
	return;
}

void insert(Listnodeptr *startptr, int data, int position)
{
	Listnodeptr currentptr = *startptr;
	Listnodeptr newnode = malloc(sizeof(Listnode));

	if(newnode!=NULL)
	{
		newnode->data = data;
		newnode->nextptr = newnode;

		if(*startptr == NULL)//if list is empty
		{
			*startptr = newnode;
		}

		else //insert data node and update head of list if necessary
		{
			while(currentptr->nextptr != *startptr)
			{
				currentptr=currentptr->nextptr;
			}
			currentptr->nextptr = newnode;
			newnode->nextptr = *startptr;

			if(position ==0)
				*startptr=newnode;

		}
	}

}

//delete implementation
void delete(Listnodeptr *startptr, int data)
{
	Listnodeptr currentptr=*startptr;
	Listnodeptr preptr=NULL;
	Listnodeptr temp;

	if(*startptr == NULL)//list is empty
	{
		return;
	}

	while(currentptr->data != data && currentptr->nextptr != *startptr)// iterate to appropriate position
	{
		preptr=currentptr;
		currentptr = currentptr->nextptr;
	}

	if(preptr==NULL && currentptr->data == data)//found at the beginning of the list
	{
		currentptr =*startptr;
		while(currentptr->nextptr != *startptr)
		{
			currentptr = currentptr->nextptr;
		}
		temp = *startptr;
		if((*startptr)->nextptr == *startptr)//if only element in the list
		{
			*startptr = NULL;
		}
		else
		{
			*startptr = (*startptr)->nextptr;
			currentptr->nextptr = *startptr;
		}
		free(temp);
	}

	else if(currentptr->data == data)//delete node and set pointers right
	{
		temp = currentptr;
		preptr->nextptr = currentptr->nextptr;
		free(temp);
	}
	else
	{
		printf("element %d not found\n",data);
	}
	return;

}


void splitList(Listnodeptr start, Listnodeptr *l1, Listnodeptr *l2)
{
	if(start==NULL || start->nextptr==start)
	{
		*l1=start;
		*l2=NULL;
		return;
	}

	Listnodeptr pre,slow,fast;

	pre=NULL;

	slow=fast=start;

	while(fast->nextptr!=start && fast->nextptr->nextptr!=start)
	{
		pre=slow;
		slow=slow->nextptr;
		fast=fast->nextptr->nextptr;
	}

	if(pre==NULL) //contains only twp nodes
	{
		*l1=start;
		*l2=start->nextptr;
		(*l1)->nextptr=*l1;
		(*l2)->nextptr=*l2;
		return;
	}

	if(fast->nextptr!=start) //if fast didn't reach the end, move it to end
	{
		pre=slow;
		slow=slow->nextptr;
		fast=fast->nextptr;
	}



	*l1=start;
	pre->nextptr=start;

	*l2=slow;
	fast->nextptr=slow;
}
	



int main()
{
	Listnodeptr startptr = NULL;
	int choice, data, i,size,n;
	
	printf("enter no of elements to be inserted: ");
	scanf("%d",&n);
	
	printf("enter all the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(&startptr, data,1);
	}
	
	printList(startptr);
	printf("\n");

	Listnodeptr first,second;
	first=NULL;
	second=NULL;

	splitList(startptr,&first, &second);
	printf("list1\n");
	printList(first);
	printf("\n");

	printf("list2\n");
	printList(second);
	printf("\n");
	return 0;
}//main



