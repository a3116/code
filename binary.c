void binary()
{
int lb,ub,mid,x;
printf("\nEnter element to search: ");
scanf("%d",&x);
lb=0;
ub=n-1;
while(lb<=ub)
{
mid=(lb+ub)/2;
if(a[mid]==x)
{
printf("\n%d found at %d position",x,mid+1);
return;
}
else if(x>a[mid])
lb=mid+1;
else
ub=mid-1;
}
printf("\n%d not found",x);
}
