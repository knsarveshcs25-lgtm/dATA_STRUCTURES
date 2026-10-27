#include<stdio.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void enqueue(int item)
{
    if(((rear==max-1)&&(front==0))||(front==rear+1))
    {
        printf("the queue is full\n");
        return;
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=item;
        return;
    }
    else if (rear==max-1)
    {
        rear=0;
        queue[rear]=item;
        return;
    }
    else
    {
        rear++;
        queue[rear]=item;
        return;
    }
}
int dequeue(){

    if(front==-1&&rear==-1)
    {
        printf("the queue is empty\n");
        return 0;
    }
    else if(front==rear)
    {
        int item=queue[front];
        front=-1;
        rear=-1;
        return item;
    }
    else if (front==max-1)
    {
        int item=queue[front];
        front=0;
        return item;
    }
    else
    {
        int item=queue[front];
        front++;
        return item;
    }

}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("the queue is empty\n");
        return;
    }
    else
    {
        printf("the queue elements are\n");
        for (int i=front;i!=rear;i=(i+1)%max)
        {
            printf("%d\n",queue[i]);
        }
        printf("%d\n",queue[rear]);
    }
}
int main()
{
    printf("1: Enqueue  \n2: Dequeue  \n3: Display Queue  \n4: Exit\n\n");
    while(1){
        int ch,ele;
        printf("Your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: {printf("Enter element: ");
                    scanf("%d", &ele);
                    enqueue(ele);
                    break;}
            case 2:{    ele = dequeue();
                        if (ele){
                        printf("Element dequeued: %d\n\n", ele);}
                        break;}
            case 3: {display();
                    break;}
            case 4:{printf("exiting the program");
                 return 0;}

        }

    }
}
