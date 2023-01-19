#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
void push(char c);
char pop();
char stack[MAX],str[30],rev[30];
int top=-1;
void main()
{
int len,i;
printf("enter string");
gets(str);
len=strlen(str);
for(i=0;i<len;i++)
push(str[i]);
for(i=0;i<len;i++)
rev[i]=pop();
rev[len]='\0';
printf("\nstring is:\n");
puts(str);
printf("\n reverse string is:\n");
puts(rev);
if(strcmp(str,rev)==0)
printf("It is palindrome");
else
printf("It is not palindrome");
}
void push(char c)
{
top++;
stack[top]=c;
}
char pop()
{
return(stack[top--]);
}

