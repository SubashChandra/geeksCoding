//given two linked lists, add them
//345 will be given as 5->4->3->null so no need to reverse while addig

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

Listnodeptr newnode(int data)
{
	Listnodeptr node = (Listnodeptr)malloc(sizeof(Listnode));
	node->data=data;
	node->next=NULL;

	return node;
}

Listnodeptr add(Listnodeptr l1, Listnodeptr l2)
{
	Listnodeptr ans=NULL,cur,temp;
	int sum, carry=0;

	while(l1!=NULL || l2!=NULL)
	{
		sum=carry+(l1?l1->data:0)+(l2?l2->data:0); //calculate sum

		carry=(sum>=10?1:0); //update carry
		sum=sum%10; //nd sum

		temp=newnode(sum); //create newnode

		//at the start or append at yhe end
		if(ans==NULL)
			ans=temp;
		else
			cur->next=temp;
		
		//update poinetr nd contiue
		cur=temp;


		if(l1)
			l1=l1->next;
		if(l2)
			l2=l2->next;
	}

	return ans;
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

	printList(list1);


	printf("enter the no of elements in the list2: ");
	scanf("%d",&n2);

	printf("enter all the elements: ");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&data);
		insert(&list2,data);
	}

	printList(list2);

	Listnodeptr ans=add(list1,list2);
	printf("sum is: \n");
	printList(ans);

	return 0;
}

