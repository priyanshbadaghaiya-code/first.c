#include <stdio.h>
#include <malloc.h>

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
void delf();
void dell();
void delN(int ,Dnode *);

int main()
{
    int n;
    
    lp = (Dnode *)malloc(sizeof(Dnode));
    create(lp);
    display(lp);
    delf(lp);
    display(lp);
    dell(rp);
    display(lp);
    printf("\nEnter the node number to be deleted:");
    scanf("%d",&n);
    delN(n,lp);
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

void delf(Dnode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nlist is empty");
        exit(0);
    }
    if (lp == rp)
    {
        lp = rp = NULL;
        free(ptr);
    }
    else
    {
        lp->next->previous = NULL;
        lp = ptr->next;
        free(ptr);
    }
}

void dell()
{
    if (rp == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDeleted last node: %d\n", rp->info);

    rp = rp->previous; // move rp one step back
    free(rp->next);    // free the old last node
    if (rp != NULL)
        rp->next = NULL; // fix the new end
    else
        lp = NULL; // list becomes empty
}
void Insert_before(int x, Dnode *ptr)
{
    Dnode *new2;
    new2 = (Dnode *)malloc(sizeof(Dnode));
    while (ptr->info != x && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n The Element does not exist:");
        exit(0);
    }
    printf("\n Enter the value to insert :");
    scanf("%d", &new2->info);

    if (ptr == lp)
    {
        new2->next = ptr;
        new2->previous = NULL;
        ptr->previous = new2;
        lp = new2;
    }
    else
    {
        ptr->previous = ptr->previous;
        new2->previous = ptr->previous;
        new2->next = ptr;
        ptr->previous = new2;
    }
    num++;
}
void delN(int n,Dnode *ptr)
{
    int ct = 1;
    Dnode *prev=NULL;
    if(lp==NULL){
        printf("\n List is empty:");
        exit(0);
    }
    while(ptr!=NULL && ct!=n){//ct=search counter.
        prev=ptr;
        ptr=ptr->next;
        ct++;
    }if(ptr==NULL){
        printf("\n node does not exist:");
        exit(0);
    }if(ptr->previous==NULL){
        lp=ptr->next;
        lp->previous=NULL;
        free(ptr);
    }else if(ptr->next==NULL){
        rp=ptr->previous;
        rp->next=NULL;
        free(ptr);
    }else{
        prev->next=ptr->next;
        ptr->next->previous=prev;
        free(ptr);
    }
    
}