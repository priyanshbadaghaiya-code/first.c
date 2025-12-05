#include<stdio.h>
#include<malloc.h>
struct Link
{
    int data;
    struct Link *next;
};
typedef struct Link Node;

Node *start;
int num; 

void insert(Node *);
void create(Node *);
void display(Node *);
int main()
{
    int ch;
    start=(Node *)malloc(sizeof(Node));
    do{
        printf("\nPress 1 for create :");
        printf("\nPress 2 for Display :");
        printf("\nPress 3 for insert new node in first:");
        printf("\nEnter your choise:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create(start);
            break;
            case 2:
            printf("\n created list is as follow :\n");
            display(start);
            break;
           
            case 3:
            insert(start);
            break;
            default:
            ch=0;
        }
    }while(ch!=0);
    return 0;
    
}
void create(Node *ptr)
{
    int ch=0;
    num = 0;
    do{
        printf("\n Input the value of the node :%d:",(num + 1));
        scanf("%d",&ptr->data);
        printf("for continue press 1->");
        scanf("%d",&ch);
        if(ch==1)
        {
            ptr->next=(Node *)malloc(sizeof(Node));
            ptr=ptr->next;
        }
        num++;
        }while(ch==1);
        ptr->next=NULL;
        printf("\n Total nodes = %d",num);

           
    }
    void display(Node *ptr){

        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
    void insert(Node *ptr){
        Node *new1;
        new1=(Node *)malloc(sizeof(Node));
        printf("\n Enter element you want to insert:");
        scanf("%d",&new1->data);
        if (start == NULL){
            new1->next=NULL;
            start=new1;
        }
        else{
            new1->next=start;
            start = new1;   
        }
    }
    