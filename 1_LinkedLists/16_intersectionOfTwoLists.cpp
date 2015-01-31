//given twoo linked lists  that intersect at a point, find it
//using szie nd tarverse the diffof lengths in the longer list nd den compare

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

//size func

int sizeOf(Listnodeptr start)
{
	int count=0;

	while(start!=NULL)
	{
		start=start->next;
		count++;
	}
	return count;
}

//pritn intersectiom of two lists
void printIntersec(Listnodeptr l1, Listnodeptr l2)
{
	int size1=sizeOf(l1);
	int size2=sizeOf(l2);

	int diff;


	//itearate the diff
	if(size1>size2)
	{
		diff=size1-size2;

		while(diff>0)
		{
			l1=l1->next;
			diff--;
		}
	}
	else if(size1<size2)
	{
		diff=size2-size1;

		while(diff>0)
		{
			l2=l2->next;
			diff--;
		}
	}
			
	//now compare

	while(l1!=NULL && l2!=NULL)
	{
		if(l1==l2)
		{
			printf("intersection at node %d\n",l1->data);
			return;
		}

		l1=l1->next;
		l2=l2->next;
	}
}
		

int main()
{
	Listnodeptr list1 = NULL;
	Listnodeptr list2 = NULL;
	int n1,n2, data, i,nValue;

	printf("enter the no of elements in the list1: ");
	scanf("%d",&n1);

	printf("enter all the elements: ");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&data);
		insert(&list1,data);
	}
	printList(list1);;

	printf("enter the no of elements in the list2: ");
	scanf("%d",&n2);

	printf("enter all the elements: ");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&data);
		insert(&list2,data);
	}
	printList(list2);

	//now create a intersection
	Listnodeptr cur=list1;
	while(cur->next!=NULL)
		cur=cur->next;

	cur->next=list2->next->next->next; //forth element of list2

	printIntersec(list1,list2);


	return 0;
}

