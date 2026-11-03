#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void insertBeginning (struct Node **head, int value)
 {
 struct Node *newNode;

newNode = (struct Node *) malloc (sizeof(struct Node));

if (newNode == NULL) {
 printf("Memory allocation failed!\n");
return;

}

newNode->data = value;
newNode->next = *head;
*head = newNode;
}
void insertEnd (struct Node **head, int value) {
 struct Node *newNode, *temp;

newNode = (struct Node *) malloc (sizeof (struct Node));

if (newNode == NULL) {
printf("Memory allocation failed!\n");
 return;

}

newNode->data = value;
newNode->next = NULL;

// If the list is empty

if (*head == NULL) {
*head = newNode;
return;
}

temp = *head;

while (temp->next != NULL) {
temp = temp->next;

}

temp->next = newNode;
}

void insertMiddle (struct Node **head, int value, int position)
{
struct Node *newNode, *temp;

int i;

if (position < 1) {
printf("Invalid position!\n");
return;
}

// Position 1 means beginning

if (position == 1) {
 insertBeginning (head, value);
return;
}

temp = *head;

//

//Traverse to the node before the position

for (i = 1; i < position-1 && temp != NULL; i++)
{

temp = temp->next;
}

if (temp == NULL) {
printf("Invalid position!\n");
return;
}

newNode = (struct Node *) malloc (sizeof (struct Node));

if (newNode == NULL) {
printf("Memory allocation failed!\n");
 return;

}

newNode->data = value;

newNode->next = temp->next;

temp->next = newNode;
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
int main()
{
    while(1)
    {
        int choice,val;
        printf("\n1.add at  beginning\n2.add at end\n3.add at position\n4.display\n5.exit\n6.create list\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{printf("enter the value\n");
                    scanf("%d",&val);
                    insertBeginning(&head,val);
                    break;}
            case 2:{printf("enter the value\n");
                    scanf("%d",&val);
                    insertEnd(&head,val);
                    break;}
            case 3:{int pos;
                    printf("enter the value and postion\n");
                    scanf("%d%d",&val,&pos);
                    insertMiddle(&head,val,pos);
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
