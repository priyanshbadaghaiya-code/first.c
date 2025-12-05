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

void create(Node *);
void display(Node *);
void delfirst(Node *);
void dellast(Node *);
void delN(Node *);
void selshort(Node *);
void reverse(Node *);
int main()
{
    int ch;

    do
    {
        printf("\nPress 1 for create :");
        printf("\nPress 2 for Display :");
        printf("\nPress 3 to delete first node:");
        printf("\nPress 4 to delete last node in list:");
        printf("\nPress 5 for delete from mid:");
        printf("\nPress 6 to short by selection short:");
        printf("\nPress 7 to reverse link list:");
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
            delfirst(start);
            break;
        case 4:
            dellast(start);
            break;
        case 5:
            delN(start);
            break;
        case 6:
            selshort(start);
            break;
        case 7:
            reverse(start);
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
        printf("%d ", ptr->data);
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
void delfirst(Node *ptr)
{
    if (start == NULL)
    {
        printf("List is Empty");
    }
    else if (start->next == NULL)
    {
        free(ptr);
        start = NULL;
    }
    else
    {
        start = ptr->next;
        free(ptr);
    }
}
void dellast(Node *ptr)
{
    Node *prv = NULL;
    if (start == NULL)
    {
        printf("List is empty:");
    }
    else
    {
        while (ptr->next != NULL)
        {
            prv = ptr;
            ptr = ptr->next;
        }
        prv->next = NULL;
        free(ptr);
    }
}
void delN(Node *ptr)
{
    int node_no, ct = 1;
    Node *prv = NULL;
    printf("\nEnter value of = ");
    scanf("%d", &node_no);
    if (start == NULL)
    {
        printf("\nLIst is empty");
    }
    else
    {

        while (ptr->data != node_no && ptr != NULL)
        {
            prv = ptr;
            ptr = ptr->next;
            ct++;
        }
        if (ct == 1)
        {
            start = ptr->next;
        }
        else if (ptr->next == NULL)
        {
            prv->next = NULL;
        }
        else if (ptr == NULL)
        {
            printf("\nTry firsey:");
        }
        else
        {
            prv->next = ptr->next;
        }
        free(ptr);
    }
}
void selshort(Node *ptr)
{
    int x;
    Node *temp;
    for (; ptr->next != NULL; ptr = ptr->next)
    {
        for (temp = ptr->next; temp != NULL; temp = temp->next)
        {
            if (ptr->data > temp->data)
            {
                x = ptr->data;
                ptr->data = temp->data;
                temp->data = x;
            }
        }
    }
}
void reverse(Node *ptr){
    Node *curr,*prv=NULL;
    curr=ptr->next;
    while (curr!=NULL){
        ptr->next=prv;
        prv=ptr;
        ptr=curr;
        curr=curr->next;
    }
        ptr->next=prv;
        start=ptr;
}
