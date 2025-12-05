//static link list
#include<stdio.h>
struct Link
{
    int data;
    struct Link *next;

};
struct Link *start,*ptr,node1,node2,node3,node4;

int main()
{
    start=&node1;
    printf("Enter Data=");
    scanf("%d",&node1.data);
    node1.next=&node2;

    printf("Enter Data=");
    scanf("%d",&node2.data);
    node2.next=&node3;

    printf("Enter Data=");
    scanf("%d",&node3.data);
    node3.next=&node4;

    printf("Enter Data=");
    scanf("%d",&node4.data);
    node4.next=NULL;

    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}