#include<stdlib.h>
#include<stdio.h>
#define MAX 5
int stack[MAX],top;
void init();
void push();
void pop();
int isfull();
int isempty();
void display();
void peek();
void main()
{
	int ch,x;
	while(1)
	{
		printf("\n Menu \n 1 init \n 2 push \n 3 pop \n 4 isfull \n 5 isempty \n 6 display \n 7 peek \n 8 exit");
		printf("\n Enter your choice: \n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();
			       break;
			case 2:push();
			       break;
			case 3:pop();
			       break;
			case 4:x=isfull();
			       if(x==-1)
			       {
				       printf("\n Stack is empty");
			       }
			       else
			       {
				       printf("\n Stack is full");
			       }
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
		        case 7:peek();
			       break;
			case 8:exit(0);
		}
	}
}
void init()
{
	top=-1;
}
int isfull()
{
	if(top==MAX-1)
	return -1;
	else
	return 0;
}
int isempty()
{
	if(top==-1)
	return -1;
	else
	return 0;
}
void push()
{
	int ele;
	if(isfull()==-1)
	{
		printf("\n Stack is full");
	}
	else
	{
		printf("\n Enter element:");
		scanf("%d",&ele);
		top++;
		stack[top]=ele;
		printf("\n Element pushed successfully");
	}
}
void pop()
{
	if (isempty()==-1)
	{
		printf("\n Stack is empty,pop operation not possible");
	}
	else
	{
		printf("\n popped element=%d",stack[top]);
		top--;
	}
}
void display()
{
	int i;
	if(isempty()==-1)
	{
		printf("\n Stack is empty,display not possible");
	}
	else
	{
		printf("\n Stack elements are:");
		for(i=top;i>=0;i--)
		printf("\n %d",stack[i]);
	}
}
void peek()
{
	if(isempty()==-1)
	{
		printf("\n Stack is empty,peek is not possible");
	}
	else
	{
		printf("\n Peeked element=%d",stack[top]);
	}
}
