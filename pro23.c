#include<stdio.h>
#include<malloc.h>

struct DLink_list
{
    struct DLink_list *previous;
    int info;
    struct DLink_list *next;
};
typedef struct DLink_list Dnode;

Dnode *lp = NULL, *rp = NULL;
int num;

/* Function prototypes */
void create(Dnode *);
void display(Dnode *);
void insertf();
void insertl();

int main()
{
    lp = (Dnode *)malloc(sizeof(Dnode));
    create(lp);
    display(lp);
    insertf();
    display(lp);
    insertl();
    display(lp);
    return 0;
}

void create(Dnode *ptr)
{
    int ch;
    num = 0;
    lp->previous = NULL;

    do
    {
        printf("\nInput the value of node %d: ", (num + 1));
        scanf("%d", &ptr->info);
        printf("For continue press 1 -> ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            ptr->next = (Dnode *)malloc(sizeof(Dnode));
            ptr->next->previous = ptr;
            ptr = ptr->next;
        }
        num++;
    } while (ch == 1);

    ptr->next = NULL;
    rp = ptr; /* rightmost pointer */
    printf("\nTotal Nodes = %d\n", num);
}

void display(Dnode *ptr)
{
    printf("\nList (left to right): ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

/* Insert at front */
void insertf()
{
    Dnode *new1 = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter element you want to insert at first: ");
    scanf("%d", &new1->info);

    new1->next = lp;
    new1->previous = NULL;
    lp->previous = new1;
    lp = new1;
}

/* Insert at last */
void insertl()
{
    Dnode *last = (Dnode *)malloc(sizeof(Dnode));
    printf("\nEnter element you want to insert at last: ");
    scanf("%d", &last->info);

    last->next = NULL;
    last->previous = rp;
    rp->next = last;
    rp = last;
}
