#include<stdio.h>
void accept();
void display();
void quicksort(int,int);
int partition(int,int);
int a[20],n;
void main()
{
	accept();
	printf("\n Unsorted array:");
	display();
	quicksort(0,n-1);
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
void quicksort(int l,int h)
{
	int p;
	if(l<h)
	{
		p=partition(l,h);
		quicksort(l,p-1);
		quicksort(p+1,h);
	}
}
int partition(int l,int h)
{
	int pivot,i,j,temp;
	pivot=a[h];
	j=l;
	i=j-1;
	for(j=l;j<h;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
	temp=a[i];
	a[i]=a[h];
	a[h]=temp;
	return i;
}
