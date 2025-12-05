/* */
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int info;
    struct NODE *Left_child;
    struct NODE *Right_child;
};
struct NODE *create_tree(int i, struct NODE *);
void Output(struct NODE *, int);

/* function to create tree*/
struct NODE *create_tree(int info, struct NODE *Node)
{
    if (Node == NULL)
    {
        Node = (struct NODE *)malloc(sizeof(struct NODE));
        Node->info = info;
        Node->Left_child = NULL;
        Node->Right_child = NULL;
        return (Node);
    }
    /* Test for the left child*/
    if (Node->info >= info)
        Node->Left_child = create_tree(info, Node->Left_child);
    else
        Node->Right_child = create_tree(info, Node->Right_child);

    return (Node);
}
/* Out put Function*/
void Output(struct NODE *T, int Level)
{
    int i;
    if (T)
    {
        Output(T->Right_child, Level + 1);
        printf("\n");
        for (int i = 0; i < Level; i++)
            printf("   ");
        printf("%d", T->info);
        printf("\n");
        Output(T->Left_child, Level + 1);
    }
}
/* Function main*/
int main()
{
    int info;
    char choice;
    struct NODE *T = (struct NODE *)malloc(sizeof(struct NODE *));
    T = NULL;
    printf("\n Input choice 'b' to break:");
    choice = getchar();
    while (choice != 'b')
    {
        printf("\n Input information of the node:");
        scanf("%d", &info);
        T = create_tree(info, T);
        printf("Root= %d\n", T->info);
        printf("\n Tree is");
        Output(T, 1);
        printf("\n Input choice 'b' to break:");
        choice = getchar();
    }
    return 0;
}