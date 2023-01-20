void probability()
{
int x,temp;
printf("\nEnter element to search: ");
scanf("%d",&x);
for(i=0;i<n;i++)
{
if(x==a[i])
{
if(i!=0)
{
temp=a[i];
a[i]=a[i-1];
a[i-1]=temp;
}
printf("\n%d found at %d position",x,i+1);
return;
}
}
printf("\n%d not found",x);
}
