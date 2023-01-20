void ordered()
{
int x;
printf("\nEnter element to search: ");
scanf("%d",&x);
if(x>a[n-1])
{
printf("\n%d not found");
return;
}
for(i=0;a[i]<x;i++);
if(a[i]==x)
{
printf("\n%d found at %d position",x,i+1);
}
else
{
printf("\n%d not found",x);
}
}
