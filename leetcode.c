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
void rev(char string[],char result[],char ch)
{
    int i,j=0;
    for (i=0;string[i]!='\0';i++)
    {
        if (string[i]!=ch)
        {
            push(string[i]);
        }
        else
        {
            result[j++]=string[i];
            while(top!=-1)
            {
                result[j++]=pop();
            }
            break;
        }

    }
    i=i+1;
    while(string[i]!='\0')
    {
        result[j++]=string[i];
        i=i+1;
    }
    result[i]='\0';
}
int main()
{
    char string[50],result[50],ch;
    printf("enter the string = ");
    scanf("%s",string);
    getchar();
    printf("enter the cahracter = ");
    scanf("%c",&ch);
    getchar();
    rev(string,result,ch);
    printf("the reversed string is = %s ",result);
}
