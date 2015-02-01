//given a linked list segregate it so thar even appears after odd
//using twp headers odd nd even
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

//even comes before odd
void segregate(Listnodeptr *start)
{
	if(*start==NULL || (*start)->next == NULL)
		return;

	Listnodeptr cur, even,odd, evenCur,oddCur,next;
	cur=*start;
	even=odd=NULL;

	while(cur!=NULL)
	{
		next=cur->next;

		if((cur->data)%2==0) //if even add to even list
		{
			if(even==NULL)
				even=cur;
			else
				evenCur->next=cur;
			evenCur=cur;
		}
		else //else addd to oddlist
		{
			if(odd==NULL)
				odd=cur;
			else
				oddCur->next=cur;
			oddCur=cur;
		}
		cur=next; //move forward
	}

	if(even) //if even set *sart to evn nd appen odd at end
	{
		*start=even;
		if(odd)
		{
			evenCur->next=odd;
			oddCur->next=NULL;
		}
		else
			evenCur->next=NULL;
		return;
	}
	else //else set *start to odd
	{
		*start=odd;
		oddCur->next=NULL;
	}
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
	segregate(&startptr);
	printList(startptr);

	return 0;
}

