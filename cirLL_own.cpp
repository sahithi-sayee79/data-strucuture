#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *head,*temp,*newnode;

void create()
{
	int i, n, value;
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	
	printf("\nEnter the head node:");
	scanf("%d",&value);
	
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	
	head = newnode;
	temp = head;
	
	for(i=1;i<n;i++)
	{
		printf("\nEnter the node %d:",(i+1));
		scanf("%d",&value);
		
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = value;
		newnode->next = NULL;
		
		temp->next = newnode;
		temp = temp->next;
	}
	temp->next = head;
}

void display()
{
	struct node *ptr;
	
	ptr = head;
	printf("\n");
	while(ptr->next!=head)
	{
		printf("%d--->",ptr->data);
		ptr = ptr->next;	
	}
	printf("%d--->",ptr->data);
}

void insert_begin()
{
	int value;
	printf("\nEnter the value of node to be inserted:");
	scanf("%d",&value);
	
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = head;
	temp = head;
	while(temp->next!=head)
		temp = temp->next;
	temp->next = newnode;
	head = newnode;
	printf("\nNode Inserted....");
}

void insert_end()
{
	int value;
	printf("\nEnter the value of node to be inserted:");
	scanf("%d",&value);
	
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	
	temp = head;
	while(temp->next!= head)
		temp = temp->next;
	temp->next = newnode;
	newnode->next = head;
	printf("\nNode Inserted....");	
}

void insert_random()
{
	int value,pos,i;
	printf("\nEnter the value of node to be inserted:");
	scanf("%d",&value);
	printf("\nEnter the position to be inserted:");
	scanf("%d",&pos);
	temp = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	for(i=1;i<pos-1;i++)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
	printf("\nNode Inserted....");
}

void delete_begin()
{
	temp = head;
	while(temp->next!= head)
		temp = temp->next;
	temp->next = head->next;
	head = head->next;
	printf("\nNode Deleted....");
}

void delete_end()
{
	temp = head;
	while(temp->next->next!=head)
		temp = temp->next;
	temp->next = head;
	printf("\nNode Deleted....");
	
}

void delete_random()
{
	int i,pos;
	printf("\nEnter the position at which the value has to be deleted:");
	scanf("%d",&pos);
	temp = head;
	for(i=1;i<pos-1;i++)
		temp = temp->next;
	temp->next = temp->next->next;
	printf("\nNode Deleted....");
}

int main()
{
	int ch;
	while(ch!=9)
	{printf("\n1.CREATE\n2.DISPLAY\n3.INSERT AT BEGINNING\n4.INSERT AT END\n5.INSERT AT RANDOM POSITION\n6.DELETE AT BEGINNING\n7.DELETE AT END\n8.DELETE AT RANDOM POSITION\n9.EXIT");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert_begin();
			display();
			break;
		case 4:
			insert_end();
			display();
			break;
		case 5:
			insert_random();
			display();
			break;
		case 6:
			delete_begin();
			display();
			break;
		case 7:
			delete_end();
			display();
			break;
		case 8:
			delete_random();
			display();
			break;
		case 9:
			printf("\nExiting...");
			break;
		default:
			printf("\n\tEnter Valid A Choice.\n");
			
	}
}
	
	return 0;
}
