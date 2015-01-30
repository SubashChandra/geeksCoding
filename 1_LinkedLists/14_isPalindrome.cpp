//given a linked list, check if its a palindrome
//reversing the second nd half nd comparing.. nd getiing bak the original list

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

void reverse(Listnodeptr *start)
{
	if(*start==NULL || (*start)->next==NULL)
		return;
	
	Listnodeptr pre,cur,next;
	pre=NULL;
	cur=*start;

	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}

	*start=pre;
}

		
int compare(Listnodeptr l1, Listnodeptr l2)
{
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->data!=l2->data) //if not equal, not a palindrome
			return 0;
		l1=l1->next;
		l2=l2->next;
	}
	if(l1!=NULL && l2==NULL) //if single node, not a palindrome
		return 0;
	else 
		return 1;
}


//return 1 if a palindrome
int isPalindrome(Listnodeptr start)
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return 0;
	}

	Listnodeptr slow,fast,pre,mid,secondHalf;
	slow=fast=start;

	mid=NULL;
	pre=start;

	while(fast!=NULL && fast->next!=NULL) //itearate to find the mid
	{
		pre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}

	if(fast!=NULL) //odd no so mid element is there
	{
		mid=slow;
		slow=slow->next;
	}
	
	secondHalf=slow; 
	pre->next=NULL;//set last node of first half to pint to NULL
	reverse(&secondHalf); //reverse second half
	int result=compare(start,secondHalf); //compare
 
	reverse(&secondHalf); //reverse back


	//reconstruct original list
	if(mid)
	{
		pre->next=mid;
		mid->next=secondHalf;
	}
	else
		pre->next=secondHalf;

	return result;
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
	printf("%s\n",(isPalindrome(startptr))==0?"not a palindrome":"is a palindrome");
	printList(startptr);


	return 0;
}

