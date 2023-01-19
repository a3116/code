#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void append();
void insert();
void count();
void search();
void del();
void delbyval();
void sort();
void reverse();
struct node
{
	int data;
	struct node *prev,*next;
}*head=NULL;
void main()
{
	int ch;
	while(1)
	{
		printf("\n MENU \n 1 create \n 2 display \n 3 append \n 4 insert \n 5 count \n 6 search \n 7 del \n 8 delbyval \n 9 sort \n 10 reverse \n 11 exit");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			       break;
			case 2:display();
			       break;
			case 3:append();
			       break;
			case 4:insert();
			       break;
			case 5:count();
			       break;
			case 6:search();
			       break;
			case 7:del();
			       break;
			case 8:delbyval();
			       break;
			case 9:sort();
			       break;
		        case 10:reverse();
				break;
		        case 11:exit(0);
		}
	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
		printf("\n Linked list is empty");
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("\n %d",temp->data);
		}
	}
}
void count()
{
	struct node *temp;
	int c=0;
	if(head==NULL)
		printf("\n Linked list is empty");
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			c++;
		}
		printf("\n No. of nodes=%d",c);
	}
}
void search()
{
	struct node *temp;
	int c=0,ele,flag=0;
	if(head==NULL)
		printf("\n Linked list is empty");
	else
	{
		printf("\n Enter element for searching:");
		scanf("%d",&ele);
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			c++;
			if(ele==temp->data)
			{
				printf("\n %d found at %d position",ele,c);
				flag=1;
			}
		}
		if(flag==0)
			printf("\n %d not found",ele);
	}
}
void sort()
{
	struct node *t1,*t2;
	int t;
	for(t1=head;t1->next!=NULL;t1=t1->next)
	{
		for(t2=t1->next;t2!=NULL;t2=t2->next)
		{
			if(t1->data>t2->data)
			{
				t=t1->data;
				t1->data=t2->data;
				t2->data=t;
			}
		}
	}
}
void create()
{
	struct node *newnode,*last;
	int n,i;
	printf("\n Enter the value of n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter data for newnode");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{
			head=newnode;
			last=newnode;
		}
		else
		{
			last->next=newnode;
			newnode->prev=last;
			last=newnode;
		}
	}
	printf("\n Linked list created successfully");
}
void append()
{
	struct node *temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the data for newnode");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=newnode;
		newnode->prev=temp;
	}
	printf("\n Node appended successfully");
}
void insert()
{
	struct node *temp=head,*newnode;
	int pos,i;
	printf("\n Enter the position");
	scanf("%d",&pos);
	if(pos<0)
	{
		printf("\n Insertion not possible");
		return;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter the data for newnode");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(pos==0)
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
	printf("\n Inserted successfully");
}
void reverse()
{
	struct node *p1,*p2,*p3;
	if(head==NULL)
	{
		printf("\n Linked list is empty");
		return;
	}
	if(head->next==NULL)
	{
		printf("\n Linked list contains single element,no need to reverse");
		return;
	}
	p1=head;
	p2=p1->next;
	p3=p2->next;
	p1->next=NULL;
	p2->prev=NULL;
	p2->next=p1;
	p1->prev=p2;
	while(p3!=NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->next;
		p2->next=p1;
		p1->prev=p2;
	}
	head=p2;
	printf("\n Reversed successfully");
}
void del()
{
	struct node *temp,*p=head;
	int pos,i;
	if(head==NULL)
	{
		printf("\n Linked list is empty,deletion not possible");
		return;
	}
	printf("\n Enter position");
	scanf("%d",&pos);
	if(pos==1)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next->prev=p;
		temp->next=NULL;
		temp->prev=NULL;
		free(temp);
	}
	printf("\n Node deleted successfully \n");
}
void delbyval()
{
}
