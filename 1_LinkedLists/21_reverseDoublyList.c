//reverse a double linked list
//O(n) time

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
	while(startptr!=NULL)
	{
		printf("%d-->",startptr->data);
		startptr = startptr->rightptr;
	}
	printf("NULL\n");
}

//insert 
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
			if(currentptr!=NULL)//if not the end of the list
			{
				newnode->rightptr=currentptr;
				currentptr->leftptr=newnode;
			}

		}
	}
}

//delete given data node from the double linked list
void delete (Listnodeptr *startptr, int data)
{
	Listnodeptr currentptr= *startptr;
	Listnodeptr preptr = NULL;
	Listnodeptr postptr;
	Listnodeptr temp;

	if(*startptr==NULL)
	{
		printf("list is empty\n");
		return;
	}

	while(currentptr!=NULL && currentptr->data != data)//iterate till the data is found or end of list is reached
	{
		preptr = currentptr;
		currentptr = currentptr->rightptr;
	}
	
	if(preptr == NULL)//data found at the beginning
	{
		temp = currentptr;
		postptr = currentptr->rightptr;
		if(postptr)//if there is a second node
		{
			postptr->leftptr = NULL; //set left of first node to null
		}
		*startptr = postptr;
		free(temp);
	}

	else if(currentptr == NULL)//data not found
	{
		printf("%d not in list\n",data);
	}


	else //data found at currentptr
	{
		temp = currentptr;
		postptr = currentptr->rightptr;
		
		preptr->rightptr = postptr;
		if(postptr!=NULL)//if end of list
			postptr->leftptr = preptr;
		
		free(temp);
	}
	return;

}


void reverse(Listnodeptr *start)
{
	if(*start==NULL || (*start)->rightptr==NULL)
		return;

	Listnodeptr temp,cur;
	
	cur=*start;

	while(cur!=NULL) //swap nd move forward
	{
		temp=cur->leftptr;
		cur->leftptr=cur->rightptr;
		cur->rightptr=temp;

		cur=cur->leftptr;
	}
	//temp now is the last second node with its pointers reversed, usually its temp->right which is teh head
	//but as pointers are reversed its temp->left
	*start=temp->leftptr;
}

int main()
{
	int data, choice,pos, i;

	int size,n;

	Listnodeptr startptr = NULL;

	printf("enter the no of elements to be entered into the list: ");
	scanf("%d",&n);
	printf("enter all the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		size = listSize(startptr);
		insert(&startptr,data,size);
	}
	printList(startptr);

	reverse(&startptr);
	printList(startptr);

	return 0;

}//main
