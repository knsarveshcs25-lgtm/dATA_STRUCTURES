// Online C compiler to run C program online
#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("stack overflow!\n");
    }
    else
    {
        printf("enter element:\n");
        scanf("%d",&item);

        top++;
        stack[top]=item;
        printf("%d is pushed into stack\n",item);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow!\n");
    }
    else
    {
        
        printf("%d is popped from stack\n",stack[top]);
          top--;
    }
}
void display()
{
    int i;
    printf("The satck elements are:\n");
    for(i=top;i>=0;i--)
    {
        
        printf("%d\n",stack[i]);
    }
}
int main()
{
    int choice;

    printf("1. push\n");
    printf("2. pop\n");
    printf("3.display\n");
    printf("4. exit\n");

     
     while(1)
         
     {
          printf("Enter your choice:\n");
     scanf("%d",&choice);

        switch(choice)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:return 0;
            
            default : printf("Invalid Choice!");
         }
     }

    
    return 0;


}
