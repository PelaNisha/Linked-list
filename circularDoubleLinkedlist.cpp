//circular double linked list

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Node{
	int info;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node NodeType;
NodeType *first= NULL;
NodeType *last = NULL;

void insert_first()
{
	NodeType *newnode;
	int el;
	newnode = (NodeType*)malloc(sizeof(NodeType));
	printf("Enter the element\n");
	scanf("%d",&el);
	newnode->info=el;
	if(first==NULL)
	{
		first=newnode;
		last=newnode;
		newnode->next = newnode;
		newnode->prev = newnode;
		printf("first node inserted\n");
	}else 
	{
		newnode->next= first;
		first->prev= newnode;
		first = newnode;
		last->next= first;
		first->prev=last;
		printf("node inserted\n");
	}
}

void insert_last()
{
	NodeType *newnode;
	int el;
	newnode = (NodeType*)malloc(sizeof(NodeType));
	printf("Enter the element\n");
	scanf("%d",&el);
	newnode->info=el;
	if(first==NULL)
	{
		first= last= newnode;
		newnode->next = newnode;
		newnode->prev = newnode;
		printf("first node inserted\n");
	}else 
	{
		newnode->prev= last;
		last->next= newnode;
		last = newnode;
		last->next= first;
		first->prev=last;
		printf("node inserted at last\n");
	}
	
}

void delete_first()
{
	NodeType *temp;
	temp = first;
	if(first==NULL)
	{
		printf("No element to delete\n");
	}else
    if(first==last){
		first=last=NULL;
		free(temp);
		printf("Deleted and now list is empty\n");
	}
	else{
		
		first = temp->next;
		last->next = first;
		first->prev= last;
		printf("First element deleted\n");
	}
}

void delete_last()
{
	NodeType *temp;
	temp = last;
	if(last==NULL)
	{
		printf("No element to delete\n");
	}else
    if(first==last){
		first=last=NULL;
		free(temp);
		printf("Deleted and now list is empty\n");
	}
	else{
		
		last= temp->prev;
		last->next = first;
		first->prev = last;
		free(temp);
		printf("Node deleted from last\n"); 
	}
	
}

void display()
{
	NodeType *temp;
	temp = first;
	if(first==NULL)
	{
		printf("Empty list\n");
	}else
	{
		while(temp!=last)
		{
			printf("%d\n", temp->info);
			temp = temp->next;
		}
		printf("%d\n", last->info);
	}
}


int main()
{

	int i,a, b;
	
	while(i!=3)
	{
		printf("Enter the option:\n1.exit\n2.insert first\n3.display\n4.Insert last\n5.Delete first\n6.Delete last\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				exit;
				break;
			case 2:
				insert_first();
				break;	
			case 3:
				display();
				break;
			case 4:
				insert_last();
				break;
			case 5:
				delete_first();
				break;
			case 6:
				delete_last();
				break;
	
		}
		
	}
}
