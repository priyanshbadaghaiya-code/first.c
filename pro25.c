#include <stdio.h>
#define SIZE 10

int top = -1, stk[SIZE], temp[SIZE];

void push();
void disp();
void pop();
void peek();
void update();
void peep();

int main()
{
    int ch;
    do
    {
        printf("\n Press 1 for Push:");
        printf("\n Press 2 for Display:");
        printf("\n Press 3 for Pop:");
        printf("\n Press 4 to peek:");
        printf("\n Press 5 to update:");
        printf("\n Press 6 to peep:");
        printf("\n Press 0 to Exit:");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            disp();
            break;
        case 3:
            pop();
            printf("\nAfter popping, values are:\n");
            disp();
            break;
        case 4:
            peek();
            break;
        case 5:
            update();
            disp();
            break;
        case 6:
            peep();
            disp();
            break;
        default:
            ch = 0;
            break;
        }
    } while (ch != 0);

    return 0;
}

// Push function
void push()
{
    int data;
    if (top >= SIZE - 1)
    {
        printf("\n Stack is Full (OVERFLOW)\n");
    }
    else
    {
        top++;
        printf("\n Enter Value: ");
        scanf("%d", &data);
        stk[top] = data;
    }
}

// Display function
void disp()
{
    if (top == -1)
    {
        printf("\n Stack is Empty\n");
    }
    else
    {
        printf("\nStack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stk[i]);
        }
        printf("\n");
    }
}

// Pop function
void pop()
{
    if (top == -1)
    {
        printf("\n Stack is Empty (UNDERFLOW)\n");
    }
    else
    {
        printf("\n Popped Element = %d\n", stk[top]);
        top--;
    }
}
void peek()
{
    int n;
    printf("ENter your choice to peek Data:");
    scanf("%d", &n);
    if (top == -1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        if ((top - n + 1) < 0 || (top - n + 1) > top)
        {
            printf("\nTry firsey\n");
        }
        else
        {
            printf("\nData= %d\n", stk[top - n + 1]);
        }
    }
}
void update()
{
    int n, data;
    printf("ENter your choice to update Data:");
    scanf("%d", &n);
    if (top == -1)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        if ((top - n + 1) < 0 || (top - n + 1) > top)
        {
            printf("\nTry firsey\n");
        }
        else
        {
            printf("\nENter New Data");
            scanf("%d", &data);
            stk[top - n + 1] = data;
        }
    }
}
void peep()
{
    int n,ct;
    printf("\nEnter position to Peep:");
    scanf("%d", &n);
    if (top == -1){
        printf("\n stack is empty");

    }else if(n>=0 && n<=top+1){
        for(int i=0;top>n-1;i++){
            temp[i]=stk[top];
            top--;
            ct++;
    }
        pop(top);
        for(int i=ct;i>=0;i--){
            top++;
            stk[top]=temp[i];

        }
    }
}