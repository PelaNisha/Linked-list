//single linked list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int info;
	struct Node *next;
};

typedef struct Node NodeType;
NodeType *first =NULL;
NodeType *last=NULL;

void insert_first(int item)
{
	int tem;
	NodeType *Newnode;
	
	Newnode = (NodeType*)malloc(sizeof(NodeType));
	if(first==NULL)
	{
		printf("\nEnter value\n");    
        scanf("%d",&tem);    
        Newnode->info = tem;
		Newnode->next = NULL;
		first = Newnode;
		last = Newnode;
	}else
	{
		printf("\nEnter value\n");    
        	scanf("%d",&tem);    
        	Newnode->info = tem;  
		Newnode->next = first;
		first = Newnode;
		printf("node inserted\n");
	}
}

void insert_last(int item)
{
	int tem;
	NodeType *Newnode;
	
	Newnode = (NodeType*)malloc(sizeof(NodeType));
	printf("\nEnter value\n");    
    scanf("%d",&tem); 
    Newnode->info = tem;
    Newnode->next= NULL;
	if(first==NULL)
	{
		
		first=last=Newnode;
	}
	else{
		last->next= Newnode;
		last=Newnode;
	}
}
void insert_at()
{
	int tem, po;
	NodeType *Newnode,*temp;
	
	Newnode= (NodeType*)malloc(sizeof(NodeType));
	printf("Enter the pos and data");
	scanf("%d%d",&po,&tem);
	Newnode->info = tem;
	if(first==NULL)
	{
		first = Newnode;
		last = Newnode;
	}else
	{
		temp = first;
		for(int i=1; i<po-1; i++)
		{
			temp = temp->next;
		}
		Newnode->next = temp->next;
		temp->next = Newnode;
	}
	
}

void delete_first()
{
	NodeType *temp;
	temp = first;
	first = temp->next;
	free(temp);
	printf("First element deleted\n");
	
}
void delete_last()
{
	NodeType *temp, *hold;
	temp = first;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}
	hold= temp->next;
	temp->next= NULL;
	free(hold);
	printf("Last element deleted\n");
	
}
void delete_at(){
	NodeType *temp, *hold;
	temp = first;
	int pos;
	printf("Enter ths pos\n");
	scanf("%d", &pos);
	for(int i =1; i<pos-1; i++)
	{
		temp = temp->next;
	}
	hold =temp->next;
	temp->next = hold->next;
	free(hold);
	printf("Elenemt deleted\n");
	
}

void display()
{
	NodeType *temp;
	temp = first;
	if(first==NULL)
	{
		printf("Empty linked list\n");
	}
	else 
	{
		while(temp!=0)
		{
			printf("%d\n", temp->info);
			temp = temp->next;
		}
	}
	
}

int main()
{
	int i, a, b,c;
	while(i!=3)
	{
		printf("Enter the request\n1.Insert\n2.Display\n3.exit\n4.Inset last\n5.Insert at\n6.Delete first\n7.Delete last\n8.Delete at\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				
				insert_first(b);
				break;
			
			case 2:
			
				display();
				break;
			case 3:
				exit;
				break;
			
			case 4:
				insert_last(b);	
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
