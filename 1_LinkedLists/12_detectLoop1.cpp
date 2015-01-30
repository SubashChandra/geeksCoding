//given a linked list detect if there is a loop
//using hash map

//O(n) time
//O(n) space

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>

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

//detect loop
void detectLoop(Listnodeptr start)
{
	if(start==NULL)
	{
		printf("empty list\n");
		return;
	}

	map<Listnodeptr,int> m1;
	map<Listnodeptr,int>::iterator i;

	Listnodeptr cur=start;

	while(cur!=NULL)
	{
		i=m1.find(cur);

		if(i==m1.end()) //if first occurrence of node, insert its address in map
		{
			m1.insert(pair<Listnodeptr,int>(cur,1));
			cur=cur->next;
		}
		else //repeating node => loop
		{
			printf("loop is present n starts at %d\n",cur->data);
			return;
		}
	}
	printf("no loop present\n");
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

	cur->next=startptr->next; //insert loop from last to second node

	detectLoop(startptr);


	return 0;
}

