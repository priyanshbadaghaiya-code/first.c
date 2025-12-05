#include <stdio.h>
#include <malloc.h>

struct Link
{
    int data;
    struct Link *next;
};
typedef struct Link Node;

Node *start = NULL;
int num;

void insert(Node *);
void create(Node *);
void display(Node *);
void insertl(Node *);
void insertmid(Node *);
void delfirst(Node *);
void dellast(Node *);
int main()
{
    int ch;

    do
    {
        printf("\nPress 1 for create :");
        printf("\nPress 2 for Display :");
        printf("\nPress 3 for insert new node in first:");
        printf("\nPress 4 to insert new node in last:");
        printf("\nPress 5 to insert new node in N:");
        printf("\nPress 6 to delete first node:");
        printf("\nPress 7 to delete last node in list:");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            create(start);
            break;

        case 2:
            printf("\nCreated list is as follows:\n");
            display(start);
            break;

        case 3:
            insert(start);
            break;
        case 4:
            insertl(start);
            break;
        case 5:
            insertmid(start);
            break;
        case 6:
            delfirst(start);
            break;
        case 7:
            dellast(start);
            break;
        default:
            ch = 0;
        }
    } while (ch != 0);
    return 0;
}

void create(Node *ptr)
{
    int ch;
    num = 0;
    if (start == NULL)
    {
        start = (Node *)malloc(sizeof(Node));
        ptr = start;
    }
    do
    {
        printf("\nInput the value of the node %d: ", (num + 1));
        scanf("%d", &ptr->data);
        printf("For continue press 1 -> ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            ptr->next = (Node *)malloc(sizeof(Node));
            ptr = ptr->next;
        }
        num++;
    } while (ch == 1);
    ptr->next = NULL; // Ensure the last node points to NULL
    printf("\nTotal nodes = %d\n", num);
}

void display(Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insert(Node *ptr)
{
    Node *new1;
    new1 = (Node *)malloc(sizeof(Node));
    printf("\nEnter element you want to insert: ");
    scanf("%d", &new1->data);
    
    if (start == NULL)
    {
        new1->next = NULL;
        start = new1;
    }
    else
    {
        new1->next = start;
        start = new1;
    }
}
void insertl(Node *ptr)
{
    Node *last;
    last = (Node *)malloc(sizeof(Node));
    printf("\n Enter element you want to insert in last:");
    scanf("%d", &last->data);
    if (start == NULL)
    {
        last->next = NULL;
        start = last;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = last;
        last->next = NULL;
    }
}
void insertmid(Node *ptr)
{
    Node *mid;
    int i,node_no,ct;
    mid = (Node *)malloc(sizeof(Node));
    printf("\nEnter Node no. = ");
    scanf("%d",&node_no);
    printf("\n Enetr element you want to insert : ");
    scanf("%d",&ptr->data);

    if(node_no==num)
    {
        while(ptr->next!=NULL)
        ptr=ptr->next;

        ptr->next= mid;
        mid->next=NULL;
    }else{
        ct=1;
        while(ct<node_no && ptr!=NULL){
            ct++;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            printf("Try Again");
        }
        else{
            mid->next=ptr->next;
            ptr->next=mid;
        } 

    }
}
void delfirst(Node *ptr){
    if(start==NULL){
        printf("List is Empty");
    }else{
        start=ptr->next;
        free(ptr);
    }
}
