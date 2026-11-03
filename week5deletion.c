#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void deleteBeginning(struct Node **head)
{
    struct Node *temp= *head;
    if (*head==NULL)
    {
        printf("the list is empty\n");
        return;
    }
    *head=temp->next;
    free(temp);
}
void deleteEnd(struct Node **head)
{
    struct Node *temp= *head;
    if (*head==NULL)
    {
        printf("the list is empty\n");
        return;
    }
    if (temp->next==NULL)
    {
        free(temp);
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return;
}
void deleteMiddle(struct Node **head,int pos)
{
    struct Node *temp,*newNode;
    if (pos<0)
    {
        printf("inavlid positon\n");
        return;
    }
    if (*head==NULL)
    {
        printf("the list is empty\n");
        return;
    }

    if(pos==1)
    {
        deleteBeginning(head);
        return;
    }
    temp=*head;
    for (int i=0;temp!=NULL && i<(pos-1);i++)
    {
        temp=temp->next;
    }
    if ((temp==NULL) || (temp->next==NULL))
    {
        printf("out of range\n");
        return;
    }
    newNode=temp->next;
    temp->next=newNode->next;
    free(newNode);

}
void display(struct Node *head)
{
    struct Node *temp= head;
    if(temp==NULL)
    {
        printf("the list empty");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp =temp->next;
    }

    printf("NULL\n");
}
void create_sllc(struct Node **head)
{
    struct Node *temp= *head;
    int x,i=0;
    printf("enter the nomber of nodes\n");
    scanf("%d",&x);
    while(i<x)
    {
        struct Node *newNode;
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->next=NULL;
        printf("enter data\n");
        scanf("%d",&(newNode->data));
        if(*head==NULL)
        {
            *head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
        i++;

    }
}
int main()
{
    while(1)
    {
        int choice,val;
        printf("\n1.delete at  beginning\n2.delete at end\n3.delete at position\n4.display\n5.exit\n6.create list\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                    deleteBeginning(&head);
                    break;}
            case 2:{
                    deleteEnd(&head);
                    break;}
            case 3:{int pos;
                    printf("enter the postion\n");
                    scanf("%d",&pos);
                    deleteMiddle(&head,pos);
                    break;}
            case 4:{display(head);
                    break;}
            case 5: {return 0;}
            case 6: {head=NULL;
                    create_sllc(&head);
                    break;}
        }
    }
}

