//merge sort a linked list

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


//iterattive split of a linked list
void split(Listnodeptr start, Listnodeptr *l1, Listnodeptr *l2)
{
	if(start==NULL)
		return;

	else if(start->next==NULL)
	{
		*l1=start;
		*l2=NULL;
		return;
	}

	Listnodeptr slow,fast,pre;
	pre=NULL;
	slow=fast=start;

	while(fast!=NULL && fast->next!=NULL)
	{
		pre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast!=NULL)
		fast=fast->next;

	*l1=start;
	pre->next=NULL;
	*l2=slow;
}

//recursive sorted merge code
Listnodeptr sortedMerge(Listnodeptr l1, Listnodeptr l2)
{
	if(l1==NULL)
		return l2;
	else if (l2==NULL)
		return l1;

	Listnodeptr result;

	if(l1->data <= l2->data)
	{
		result=l1;
		result->next=sortedMerge(l1->next,l2);
	}
	else
	{
		result=l2;
		result->next=sortedMerge(l1,l2->next);
	}
	return result;
}
		
//recursive merge sort
void mergeSort(Listnodeptr *start)
{
	Listnodeptr cur, l1,l2;

	cur=*start;

	if(cur==NULL || cur->next==NULL)
		return;

	split(cur,&l1,&l2); //split the list

	//recursively both halves
	mergeSort(&l1); 
	mergeSort(&l2);

	//now sorted merge them
	*start=sortedMerge(l1,l2);
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
	mergeSort(&startptr);
	printf("sorted list\n");
	printList(startptr);


	return 0;
}

