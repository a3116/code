void linear()
{
int x,flag=0;
printf("\nEnter an element to search: ");
scanf("%d",&x);
for(i=0;i<n;i++)
{
if(x==a[i])
{
printf("\n%d found at %d position",x,i+1);
flag=1;
}
}
if(flag==0)
printf("\n%d not found",x);
}
