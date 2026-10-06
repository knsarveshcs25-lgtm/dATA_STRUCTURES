#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int item)
{
    if (rear==(MAX-1))
    {
        printf("queue is full (queue overflow)\n");
        return;
    }
    else if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=item;
    printf("item %d added to queue\n",item);
}
int dequeue()
{
    if(front==-1||front>rear)
    {
        printf("queue empty (queue underflow)\n");
        return -1;
    }
    int value=queue[front];
    front++;
    printf("item %d removed from queue\n",value);
    return value;
}
void display()
{
    if(front==-1||front>rear)
    {
        printf("queue empty cant display anything (queue underflow)\n");
    }
    else
    {
        printf("the elements of the QUEUE are:\n");
        for (int i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    while(1)
    {
    int choice;
    printf("choose an option\n1.insert\n2.delete\n3.display\n4.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{int item;
                printf("enter the item to insert : ");
                scanf("%d",&item);
                enqueue(item);
                break;}
        case 2:
            {
                int del_item=dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:{
            printf("exiting the program\n");
                   return 0;}

    }
    }
}
