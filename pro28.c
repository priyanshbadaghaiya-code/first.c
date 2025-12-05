#include <stdio.h>
#define SIZE 10
int f=-1,r=-1,que[SIZE];
void insert ();
void del();
void show();
int main ()
{
    int ch;
    do{
        printf("\nPress 1 for Insert:");
        printf("\nPress 2 for show:");
         printf("\nPress 3 for Delete:");
          printf("\nEnter your choise:");
        scanf("%d",&ch);
           switch (ch)
           {
               case 1: insert();
                    break;
              case 2:show();
                    break;
            case 3: del();
                    break;
            default:
                 ch=0;
                 break;
        
           }
        
    }while (ch!=0);
    return 0;
}    
// main function closed
void insert()
{
    int data ;
    printf("Enter Data:");
    scanf("%d",&data);
    if(r==SIZE-1)
    {
        printf("\nQueue is not Empty:\n");
        
    }else{
        r++;
        que[r]=data;
             if (f==-1)
             {
                 f=0;
                 
             }
    }
}
void show()
{
    if(r==-1)
    {
        printf("\nQueue is Empty\n");
        
    }else{
        for(int i=f;i<=r;i++)
        {
            printf("%d\t",que[i]);
            
        }
    }
}
void del()
{
    if(f==-1)
    {
        printf("\nQueue is Empty\n");
        
    }else{
        que[f]=0;  
          if(f==r)
       {
           f=-1;
           r=-1;
       }else{
           f=f=1;
       }
    }
}