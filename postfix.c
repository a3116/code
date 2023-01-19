#include<stdio.h>
#include<string.h>
#define MAX 30
char infix[MAX],postfix[MAX],stack[MAX];
int top;
void infixtopostfix();
void push(char);
char pop();
int precedance(char);
void main()
{
      printf("\n enter the infix string");
      gets(infix);
      infixtopostfix();
      printf("\n postfix string=%s",postfix);
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
int precedance(char c)
{
      switch(c)
      {
            case '^':return 3;
            case '*':
            case '/':
            case '%':return 2;
            case '+':
            case '-':return 1;
            case '(':return 0;
      }
}
void infixtopostfix()
{
      int len,i,p=0,x,y;
      stack[top]='#';
      len=strlen(infix);
      infix[len]='#';
      for(i=0;i<len;i++)
      {
            switch(infix[i])
            {
                  case '(':push(infix[i]);
                         break;
                  case '+':
                  case '-':
                  case '*':
                  case '/':
                  case '%':
                  case '^':
                  x=precedance(infix[i]);
                  while(stack[top]!='#'&&(x<=precedance(stack[top])))
                  {
                        postfix[p++]=pop();
                  }
                  push(infix[i]);
                  break;
                  case ')':
                  while(y=pop()!='(')
                  {
                        postfix[p++]=y;
                  }
                  break;
                  default:
                  postfix[p++]=infix[i];
            }
      }
      while(stack[top]!='#')
      {
            postfix[p++]=pop();
      }
      postfix[p]='\0';
}
