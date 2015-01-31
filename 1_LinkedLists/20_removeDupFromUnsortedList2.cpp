//remove duplicates from a unsorted list
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

//given an unsorted linked list
void removeDuplicates(Listnodeptr start)
{
	if(start==NULL || start->next==NULL)
		return;

	map<int,int> m1;
	map<int,int>::iterator i;

	Listnodeptr temp;
	//insert teh first node data into map
	m1.insert(pair<int,int>(start->data,1));
	
	while(start->next!=NULL)
	{
		i=m1.find(start->next->data);

		if(i!=m1.end()) //if already present, deleet start->next
		{
			temp=start->next;
			start->next=start->next->next;
		}

		else //isnert, start->next nd move forward
		{
			m1.insert(pair<int,int>(start->next->data,1));
			start=start->next;
		}
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
	removeDuplicates(startptr);
	printList(startptr);



	return 0;
}

