//trie insert nd search

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define ALPHABET_SIZE (26)

//conevrt key current character into index
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


//trie node

struct trienode
{
	int value;
	struct trienode *children[ALPHABET_SIZE]; //an array of pointers to children of next level
};

typedef struct trienode Trienode;
typedef Trienode *Trienodeptr;

//trie adt

struct trie
{
	Trienodeptr root;
	int count;
};

typedef struct trie Trie;
typedef Trie *Trieptr;



//rturn new trie node initiated to NULL's
Trienodeptr getnode()
{
	Trienodeptr temp = (Trienodeptr)malloc(sizeof(Trienode));
	if(temp)
	{
		int i;
		temp->value=0;

		for(i=0;i<ALPHABET_SIZE;i++)
			temp->children[i]=NULL;

	}
	return temp;
}


//initialize the trie(root is dummy node
void initialize(Trieptr *atrie)
{
	*atrie = (Trieptr)malloc(sizeof(Trie));
	(*atrie)->root=getnode(); //dummy node
	(*atrie)->count=0;
}


//if key is present as prefix of some exiting key, set last node of key as leaf, else create nodes nd set leaf node
void insert(Trieptr atrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	Trienodeptr node;

	atrie->count++;
	node = atrie->root;

	//iterate through the key
	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);
		if(node->children[index]==NULL) //if node for the char doesn't exist
		{
			node->children[index]=getnode();
		}
		node = node->children[index]; //go to the desired node
	} 

	//mark last node as leaf
	node->value = atrie->count;
}



//returns non-zero if key is present in trie
int search(Trieptr atrie, char key[])
{
	int level;
	int length = strlen(key);
	int index;
	Trienodeptr node;

	node = atrie->root;

	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);
		if(node->children[index]==NULL)
		{
			return 0;
		}


		node = node->children[index];
	}
	return (node!=NULL && node->value);
}


int main()
{
	Trieptr atrie;;
	initialize(&atrie);
	

	int choice;
	char key[100];

	
	printf("1 to insert, 2 to search nd 3 to exit: ");
	scanf("%d",&choice);
	while(choice!=3)
	{
		switch(choice)
		{
			case 1:
				scanf("%s",key);
				insert(atrie, key);
				printf("%s inserted nd trie size: %d\n",key,atrie->count);
				break;

			case 2:
				scanf("%s",key);
				printf("%s is %s\n",key, search(atrie,key)?"present":"not present");
				break;

			default:
				printf("invalid choice\n");
		}
		printf("1 to insert, 2 to search nd 3 to exit: ");
		scanf("%d",&choice);
	}

			
	

	return 0;
}

