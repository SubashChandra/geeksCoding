//trie insert, search nd delete
//O(sizeof(key))

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
Trieptr insert(Trieptr atrie, char key[])
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
	return atrie;
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

int isFree(Trienodeptr node)
{
	int i;
	for(i=0;i<ALPHABET_SIZE;i++)
	{
		if(node->children[i]) //if not null
			return 0;
	}
	return 1;
}



int deleteHelper(Trienodeptr node, char key[], int level, int len)
{
	if(node)
	{
		if(level==len) //base case
		{
			if(node->value)
			{
				//unmaek leaf node
				node->value = 0;
				//if empty, node to vbe deleted
				if(isFree(node))
				{
					return 1;
				}
				return 0;
			}
		}
		else //recursion
		{
			int index=CHAR_TO_INDEX(key[level]);
			if(deleteHelper(node->children[index],key,level+1,len))
			{
				//lastnode marked delete it
				free(node->children[index]);
				node->children[index]=NULL;

				//recursively delete eligible nodes
				return 	(isFree(node) && node->value!=0); //if freenode nd not a leaf node, return 1 to tell the prev func to deletedis node

			}
		}
	}
	return 0;
}






void deleteNode(Trieptr atrie, char key[])
{
	int size = strlen(key);
	if(size>0)
		deleteHelper(atrie->root,key,0,size);
}



int main()
{
	Trieptr atrie;;
	initialize(&atrie);
	

	int choice;
	char key[100];

	
	printf("1 to insert, 2 to search,3 to delete nd 4 to exit: ");
	scanf("%d",&choice);
	while(choice!=4)
	{
		switch(choice)
		{
			case 1:
				scanf("%s",key);
				atrie = insert(atrie, key);
				printf("%s inserted nd trie size: %d\n",key,atrie->count);
				break;

			case 2:
				scanf("%s",key);
				printf("%s is %s\n",key, search(atrie,key)?"present":"not present");
				break;

			case 3:
				scanf("%s",key);
				deleteNode(atrie,key);
				break;

			default:
				printf("invalid choice\n");
		}
		printf("1 to insert, 2 to search nd 3 to exit: ");
		scanf("%d",&choice);
	}

			
	

	return 0;
}

