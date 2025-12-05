#include <stdio.h>
int main()
{
    int a[10], i, j, temp;

    printf("\n Enter the value of array :");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d\t", a[i]);
    }
}