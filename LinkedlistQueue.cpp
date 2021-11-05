//linked list implementation of linear queue
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Node{
	int info;
	struct Node *next;
};
typedef struct Node node;
node *front=0;
node *rear=0;
void insert();
void delet();
void display();

void insert(){
	node *newnode;
	int el;
	newnode = (node*)malloc(sizeof(node));
	printf("Enter the element\n");
	scanf("%d", &el);
	newnode->info = el;
	if(rear==0)
	{
		printf("Storing first element\n");
		rear=front=newnode;
		newnode->next=NULL;
	}
	else
	{
		rear->next=newnode;
		newnode->next= NULL;
		rear= newnode;
	}
}

void delet()
{
	node *temp;
	if(front==0)
	{
		printf("Nothing to delete\n");
	}else if(front==rear)
	{
		temp = front;
		rear = front = NULL;
		free(temp);
		printf("element deleted from front and now list is empty\n");
	}else
	{
		temp = front;
		front=front->next;
		free(temp);
		printf("element deleted from front\n");
	}
}
void display()
{
	node *temp;
	if(front==0)
	{
		printf("Nothing to display\n");
	}else 
	{
		temp = front;
		while(temp!=NULL)
		{
			printf("\t%d\n", temp->info);
			temp=temp->next;
		}
		
	}
}
int main()
{
	int i, a, b,c;
	while(i!=3)
	{
		printf("Enter the request\n1.Insert\n2.Display\n3.exit\n4.Delete\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				exit;
				break;
			case 4:
				delet();	
				break;

		}
	}
}
