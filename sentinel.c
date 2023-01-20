void sentinel()
{
int x,i;
printf("\nEnter an element to search: ");
scanf("%d",&x);
a[n]=x;
for(i=0;a[i]!=x;i++);
if(i==n)
printf("\n%d not found",x);
else
printf("\n%d found at %d position",x,i+1);
}
