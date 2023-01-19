#include<stdlib.h>
#include<stdio.h>
#define MAX 5
int queue[MAX],rear,front;
void init();
void add();
void del();
int isfull();
int isempty();
void peek();
void display();
void main()
{
	int ch,x;
	while(1)
	{
		printf("\n Menu \n 1 init \n 2 add \n 3 del \n 4 isfull \n 5 isempty \n 6 peek \n 7 display \n 8 exit");
		printf("\n Enter your choice \n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();
			       break;
			case 2:add();
			       break;
			case 3:del();
			       break;
			case 4:x=isfull();
			       if(x==-1)
			       {
				       printf("\n Queue if full");
			       }
			       else
			       {
				       printf("\n Queue if not full");
			       }
			       break;
		        case 5:x=isempty();
			       if(x==-1)
			       {
				       printf("\n Queue is empty");
			       }
			       else
			       {
				       printf("\n Queue is not empty");
			       }
			       break;
			case 6:peek();
			       break;
			case 7:display();
			       break;
			case 8:exit(0);
		}
	}
}
void init()
{
	rear=-1;
	front=-1;
}
int isfull()
{
	if(rear==MAX-1)
		return -1;//full
	else
		return 0;//not full
}
int isempty()
{
	if(((rear==-1)&&(front==-1))||(front==rear+1))
		return -1; //empty
	else
		return 0;//not empty
}
void add()
{
	int ele;
	if(isfull()==0)
	{
		printf("\n Enter the element: ");
		scanf("%d",&ele);
		rear++;
		queue[rear]=ele;
		printf("\n Element added successfully");
		if(front==-1)
			front=0;
	}
	else
	{
		printf("\n Queue is full");
	}
}
void del()
{
       if(isempty()==-1)
       {
	       printf("\n Queue is empty,delete operation not possible");
       }
       else
       {
	       printf("\n Deleted element=%d",queue[front]);
	       front++;
       }
}
void peek()
{
	if(isempty()==-1)
	{
		printf("\n Queue is empty,peek is not possible");
	}
	else
	{
		printf("\n Peeked element=%d",queue[front]);
	}

}
void display()
{
	int i;
	if(isempty()==0)
	{
		printf("\n Queue is:");
		for(i=front;i<=rear;i++)
		{
			printf("\n %d",queue[i]);
		}
	}
	else
	{
		printf("\n Queue is empty,display not possible");
	}

}

