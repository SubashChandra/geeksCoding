//given a linked list, alternate split it into two lists
//iterative

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



void altSplit(Listnodeptr *start, Listnodeptr *l1,Listnodeptr *l2)
{
	if(*start==NULL)
	{
		return;
	}

	if((*start)->next==NULL) //if single node case
	{
		*l1=*start;
		*start=NULL;
		*l2=NULL;
		return;
	}

	Listnodeptr temp1,temp2,cur,sec,next;
	temp1=NULL;
	temp2=NULL;
	cur=*start;

	while(cur!=NULL && cur->next!=NULL)
	{
		sec=cur->next;
		next=sec->next;


		//append to teh first list
		if(*l1==NULL)
		{
			*l1=cur;
			temp1=cur;
		}
		else
		{
			temp1->next=cur;
			temp1=cur;
		}
		
		//append to the second list
		if(*l2==NULL)
		{
			*l2=sec;
			temp2=sec;
		}
		else 
		{
			temp2->next=sec;
			temp2=sec;
		}

		cur=next; //update cur
	}

	if(cur!=NULL) //if odd lenght, append it to the first list
	{
		temp1->next=cur;
		temp2->next=NULL;
	}

	else
	{
		temp1->next=NULL;
		temp2->next=NULL;
	}
	*start=NULL;
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
	Listnodeptr l1,l2;
	l1=NULL;
	l2=NULL;
	altSplit(&startptr,&l1,&l2);

	printList(startptr);
	printList(l1);
	printList(l2);


	return 0;
}

