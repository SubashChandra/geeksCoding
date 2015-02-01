//given a linked list detect if there is a loop, nd remove it
//using two pointers slow nd fast, find lenght of loop, nd use two pointers, one at start nd other at k th node nd fid their meeting point
//the start of loop, nd break loop

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

//detect loopi nd break it
void removeLoop(Listnodeptr start)
{
	if(start==NULL)
	{
		printf("empty list\n");
		return;
	}

	Listnodeptr slow, fast,pre;
	slow=fast=start;

	while(fast!=NULL && fast->next!=NULL) //check for NULL
	{
		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast) //if they match, loop exists
		{
			printf("loop present\n");
			break;
		}
	}
	
	if(slow!=fast)
	{
		printf("no loop present\n");
		return;
	}

	//fidn length of loop
	int count=1;
	while(fast->next!=slow)
	{
		fast=fast->next;
		count++;
	}
	printf("loop length: %d\n",count);

	//now use two pointers one at the start nd one at teh k th node (count)
	slow=fast=start;
	while(count>0)
	{
		pre=slow;
		slow=slow->next;
		count--;
	}

	//now compare nd set the next of pre to null when they meet
	while(slow!=fast)
	{
		pre=slow;
		slow=slow->next;
		fast=fast->next;
	}
	printf("loop starting point %d\n",slow->data);
	pre->next=NULL;

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
	Listnodeptr cur=startptr;
	while(cur->next!=NULL)
		cur=cur->next;

	printf("loop inserted\n");
	cur->next=startptr->next; //insert loop from last to second node

	removeLoop(startptr);
	printList(startptr);


	return 0;
}

