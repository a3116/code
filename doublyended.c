#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],rear,front;
void init();
void isempty();
void isfull();
void getfront();
void getrear();
void addfront();
void deletefront();
void addrear();
void deleterear();
void main()
{
	int ch;
	while(1)
	{
		printf("\n Menu \n 1 init \n 2 isempty \n 3 isfull \n 4 getfront \n 5 getrear \n 6 addfront \n 7 deletefront \n 8 addrear \n 9 deleterear \10 exit");
		printf("\n Ener your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:init();
			       break;
			case 2:isempty();
			       break;
			case 3:isfull();
			       break;
			case 4:getfront();
			       break;
			case 5:getrear();
			       break;
			case 6:addfront();
			       break;
			case 7:deletefront();
			       break;
			case 8:addrear();
			       break;
			case 9:deleterear();
			       break;
			case 10:exit(0);
		}
	}
}
void init()
{
	rear=-1;
	front=-1;
}
void isempty()
{
	if(front==-1)
		printf("\n Queue is empty");
	else
		printf("\n Queue is not empty");
}
void isfull()
{
	if((front==0 && rear==MAX-1)||(front==rear+1))
		printf("\n Queue is full");
	else
		printf("\n Queue is not full");
}
void addrear()
{
	int ele;
	if((front==0 && rear==MAX-1)||(front==rear+1))
	{
		printf("\n Queue is overflow");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(rear==MAX-1)
			rear=0;
		else
			rear=rear+1;
	}
	printf("\n Enter the element:");
	scanf("%d",&ele);
	a[rear]=ele;
}
void addfront()
{
	int ele;
	if((front==0 && rear==MAX-1)||(front==rear+1))
	{
		printf("\n Queue is overflow");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		if(front==0)
			front=MAX-1;
		else
			front=front-1;
	}
	printf("\n Enter the element:");
	scanf("%d",&ele);
	a[front]=ele;
}
void deletefront()
{
	if(front==-1)
	{
		printf("\n Queue is underflow");
		return;
	}
	printf("\n Deleted element is:%d",a[front]);
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	if(front==MAX-1)
		front=0;
	else
		front=front+1;
}
void deleterear()
{
	if(front==-1)
	{
		printf("\n Queue is underflow");
		return;
	}
	printf("\n Deleted element is:%d",a[rear]);
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(rear==0)
			rear=MAX-1;
		else
			rear=rear-1;
	}
}
void getfront()
{
	if(front==-1)
		printf("\n Queue is empty,getfront not possible");
	else
		printf("\n front element=%d",a[front]);
}
void getrear()
{
	if(front==-1)
		printf("\n Queue is empty,peek not possible");
	else
		printf("\n Rear element is=%d",a[rear]);
}
