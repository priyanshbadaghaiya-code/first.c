#include <stdio.h>
#include <malloc.h>
struct Link
{
    int data;
    struct Link *next;
};
typedef struct Link Node;

Node *start = NULL;

void insert(Node *);
void disp(Node *);
void insertfirst();

int main()
{
    int ch;
    start = (Node *)malloc(sizeof(Node));
    insert(start);
    disp(start);
    insertfirst();
    disp(start);
    return 0;
}
void insert(Node *ptr)
{
    int ch = 0;
    do
    {
        printf("Enetr the data:");
        scanf("%d", &ptr->data);
        printf("for new link node");
        scanf("%d", &ch);
        if (ch == 1)
        {
            ptr->next = (Node *)malloc(sizeof(Node));
            ptr = ptr->next;
        }
    } while (ch == 1);
    ptr->next = NULL;
}

void disp(Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void insertfirst()
{
    Node *nn;
    nn = (Node *)malloc(sizeof(Node));
    printf("Enter Data:");
    scanf("%d", &nn->data);
    if (start == NULL)
    {
        start = nn;
        nn->next = NULL;
    }
    else
    {
        nn->next = start;
        start = nn;
    }
}
