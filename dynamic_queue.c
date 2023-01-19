#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front,*rear;
void init();
void add();
void del();
void display();
void peek();
int isempty();
void main()
{
	int ch,x;
	while(1)
	{
		printf("\n Menu \n 1 init \n 2 add \n 3 del \n 4 display \n 5 peek \n 6 isempty \n 7 exit");
                printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();
			       break;
			case 2:add();
			       break;
			case 3:del();
			       break;
			case 4:display();
			       break;
			case 5:peek();
			       break;
                        case 6:x=isempty();
			       if(x==-1)
			       {
				       printf("\n Queue is empty");
			       }
			       else
			       {
				       printf("\n Queue is not empty");
			       }
			       break;
			case 7:exit(0);
		}
	}
}
void init()
{
	front=rear=NULL;
}
void peek()
{
	if(front==NULL)
	{
		printf("\n Queue is empty,peek not possible");
	}
	else
	{
		printf("\n Peeked element=%d",front->data);
	}
}
int isempty()
{
	if(front==NULL)
		return -1;
	else

		return 0;
}
void add()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the data for newnode:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(front==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	printf("\n Element added successfully");
}
void del()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("\n Queue is empty,delete not possible");
		return;
	}
	temp=front;
	front=front->next;
	temp->next=NULL;
	printf("\n Deleted element=%d",temp->data);
	free(temp);
}
void display()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("\n Queue is empty");
	}
	else
	{
		for(temp=front;temp!=NULL;temp=temp->next)
		{
			printf("\n %d",temp->data);
		}
	}
}
