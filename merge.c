#include<stdio.h>
void accept();
void display();
void mergesort(int,int);
void merge(int,int,int);
int a[20],n;
void main()
{
	accept();
	printf("\n Unsorted array:");
	display();
	mergesort(0,n-1);
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
void mergesort(int l,int h)
{
	int mid;
	if(l!=h)
	{
		mid=(l+h)/2;
		mergesort(l,mid);
		mergesort(mid+1,h);
		merge(l,mid,h);
	}
}
void merge(int l,int mid,int h)
{
	int i,j,k,temp[20];
	i=l;
	j=mid+1;
	k=l;
	while((i<=mid)&&(j<=h))
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=h)
		temp[k++]=a[j++];
	for(i=0;i<k;i++)
		a[i]=temp[i];

}
