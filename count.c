#include<stdio.h>
void accept();
void display();
void countsort();
int a[20],c[20],b[20],n;
void main()
{
	accept();
	printf("\n Unsorted array:");
	display();
	countsort();
	printf("\n Sorted array:");
	display();
}
void accept()
{
	int i;
	printf("\n Enter limit:");
	scanf("%d",&n);
	printf("\n Enter array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void display()
{
	int i;
	printf("\n Array display");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
}
void countsort()
{
	int max,i;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	for(i=1;i<=max;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		c[a[i]]--;
		b[c[a[i]]]=a[i];
	}
	for(i=0;i<n;i++)
		a[i]=b[i];
}
