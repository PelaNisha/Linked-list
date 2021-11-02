// double linked list
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Node{
	int info;
	struct Node *next;
	struct Node *prev;
};

typedef Node NodeType;
NodeType *first= NULL;
NodeType *last = NULL;

void insert_first()
{
	NodeType *Newnode;
	int el;
	Newnode= (NodeType*)malloc(sizeof(NodeType));
	printf("enter the element\n");
	scanf("%d", &el);
	Newnode->info = el;
	if(first==NULL)
	{
		first =Newnode;
		last = Newnode;
	}else{
		
	
	Newnode->next = first;
	first->prev =Newnode;
	first= Newnode;
	}
	printf("Element inserted\n");
}

void insert_last()
{
	NodeType *Newnode;
	int el;
	Newnode= (NodeType*)malloc(sizeof(NodeType));
	printf("enter the element\n");
	scanf("%d", &el);
	Newnode->info = el;
	if(first==NULL)
	{
		first =Newnode;
		last = Newnode;
	}else
	{
		last->next= Newnode;
		Newnode->prev = last;	
		last = Newnode;
	
	}
	printf("Element inserted\n");
}

void delete_first()
{
	NodeType *temp;
	temp = first;
	if(first==NULL)
	{
		printf("List was empty so cannot delete\n");
	}else if(first==last)
	{
		first=last=NULL;
		free(temp);
		printf("Single element deleted so list is now empty\n");
	}else
	{
		first= first->next;
//		last->next= first;
		free(temp);
		printf("Deleted\n");
	}
}

void delete_last()
{
	NodeType *temp, *hold;
	temp= last;
	if(first==NULL)
	{
		printf("No node to be deleted\n");
	}else
	if(first== last)
	{
		first=last= NULL;
		free(temp);
		printf("Node deleted and now empty list\n");
	}else
	{
		hold = last;
		last= temp->prev;
//		last->next= first;
		free(hold);
		printf("item deleted from last\n");
		
	}
}
void display()
{
	NodeType *temp;
//	Newnode = (NodeType*)malloc(sizeof(NodeType));
	if(first==NULL)
	{
		printf("Nothing to display\n");
	}else
	{
		temp = first;
		while(temp!=last)
		{
			printf("%d\n",temp->info);
			temp = temp->next;
		}
		printf("%d\n",last->info);
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
//				break;
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
