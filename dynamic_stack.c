#include<stdio.h>
#include<stdlib.h>
void init();
void push();
void pop();
void peek();
int isempty();
void display();
struct node
{
	int data;
	struct node *next;
}*top;
void main()
{
	int ch,x;
	while(1)
	{
		printf("\n Menu \n 1 init \n 2 push \n 3 pop \n 4 peek \n 5 isempty \n 6 display \n 7 exit");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();
			       break;
			case 2:push();
			       break;
			case 3:pop();
			       break;
			case 4:peek();
			       break;
			case 5:x=isempty();
			       if(x==-1)
			       {
				       printf("\n Stack is empty");
			       }
			       else
			       {
				       printf("\n Stack is not empty");
			       }
			       break;
			case 6:display();
			       break;
			case 7:exit(0);
		}
	}
}
void init()
{
	top==NULL;
}
void peek()
{
	if(top==NULL)
	{
		printf("\n Stack is empty,peek not possible");
		return;
	}
	printf("\n Peeked element=%d",top->data);
}
void pop()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("\n Stack is empty,pop not possible");
		return;
	}
	temp=top;
	top=top->next;
	temp->next=NULL;
	printf("\n Popped element=%d",temp->data);
	free(temp);
}
int isempty()
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void push()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the data for newnode:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->next=top;
	top=newnode;
	printf("\n Push operation done successfully");
}
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("\n Stack is empty");
	}
	else
	{
		for(temp=top;temp!=NULL;temp=temp->next)
		{
			printf("\n %d",temp->data);
		}
	}
}
