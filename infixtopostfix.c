#include<stdio.h>
#include<string.h>
#define max 50
char  stack[max];
int top =-1;
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default :
            return 0 ;
    }
}
void infixtopostfix(char postfix[],char infix[])
{
    int i;
    int j=0;
    push('(');
    int len=strlen(infix);
    infix[len]=')';
    infix[len+1]='\0';
    len=strlen(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        char ch=infix[i];
        if (ch=='(')
        {
            push(ch);
        }
        else if (ch==')')
        {
            while(top!=-1 &&stack[top]!='(')
            {
                postfix[j++]=pop();
            }
            pop();
        }
        else if (precedence(ch)==0)
        {
            postfix[j++]=ch;
        }
        else
        {
            while(top!=-1&& stack[top]!='(' && precedence(stack[top])>=precedence(ch))
            {
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1)
    {
        postfix[j++]=pop();

    }
    postfix[j]='\0';
    for(int i=0;postfix[i]!='\0';i++)
    {
        if (postfix[i]=='('||postfix[i]==')')
        {
             for(int j=0;postfix[j]!='\0';j++)
             {
                 postfix[j]='-';
             }
        }
    }
}
int main()
{
    char postfix[50],infix[50];
    printf("enter the infix expression = ");
    scanf("%s",&infix);
    infixtopostfix(postfix,infix);
    printf("the postfix expression is = %s ",postfix);
}
