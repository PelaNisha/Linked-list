//circular linked list

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
	int info;
	struct Node *next;
	
};

typedef Node NodeType;
NodeType *first=NULL;
NodeType *last=NULL;

void insert_first()
{
	int a;
	NodeType *Newnode;
	Newnode = (NodeType*)malloc(sizeof(NodeType));
	printf("Enter the number\n");
	scanf("%d", &a);
	Newnode->info =a;
	if(first==NULL)
	{

		Newnode->next = Newnode;
		first = Newnode;
		last = Newnode;
		printf("Node inserted first\n");
	}else
	{
		Newnode->info =a;
		Newnode->next=first;
		first = Newnode;
		last->next = Newnode;
		printf("Node inserted\n");
	}
}

void insert_last()
{
	int a;
	NodeType *Newnode;
	Newnode=(NodeType*)malloc(sizeof(NodeType));
	printf("Enter the number\n");
	scanf("%d", &a);
	Newnode->info =a;
	if(first==NULL)
	{
		Newnode->next = Newnode;
		first= Newnode;
		last = Newnode;
	}else
	{
		last->next = Newnode;
		last= Newnode;
		Newnode->next= first;
		
	}
	
	
}

void insert_at()
{
	int a, po;
	NodeType *Newnode, *temp;
	Newnode=(NodeType*)malloc(sizeof(NodeType));
	printf("Enter the pos and number\n");
	scanf("%d%d", &po, &a);
	Newnode->info =a;
	temp = first;
	
	for(int i=1; i<po-1; i++)
	{
		temp = temp->next;
	}
	Newnode->next=temp->next;
	temp->next =Newnode;
	printf("Inserted!");
	
}

void delete_first()
{
	
	NodeType *temp;
	temp= first;
	if(first==NULL)
	{
		printf("Empty List so can't delete\n'");
	}
	if(first==last)
	{
		first=last=NULL;
		free(temp);
	}else
	{
	
		first = first->next;
		last->next= first;
		free(temp);
	}
}

void delete_last()
{
	NodeType *temp;
	temp = last;
	if(first==NULL)
	{
		printf("Empty List so can't delete\n'");
	}
	if(first==last)
	{
		first=last=NULL;
		free(temp);
	}else
	{
		while(temp->next!=last)
		{
			temp = temp->next;
		}
	
		last= temp;
		temp= temp->next;
		last->next=first;
		free(temp);
	}	
}
void delete_at()
{
	int po;
	NodeType *temp, *hold;
	temp = first;
	printf("Enter the position\n");
	scanf("%d", &po);
	for(int i = 1; i<po-1; i++)
	{
		temp = temp->next;
	}
	hold= temp->next;
	temp->next = hold->next;
	free(hold);

}
void display()
{
	NodeType *temp;

	if(first==NULL)
	{
		printf("Empty linked list\n");
	}else
	{
		temp=first;
		while(temp!=last)
		{
			printf("%d\n",temp->info);
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
		printf("Enter the option:\n1.exit\n2.insert first\n3.display\n4.Insert last\n5.Insert at\n6.Delete first\n7.Delete last\n8.Delete at\n");
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
				insert_at();
				break;	
			case 6:
				delete_first();
				break;
			case 7:
				delete_last();
				break;
			case 8:
				delete_at();
				break;		
						
		}
		
	}
}
