#include <stdio.h>
int main()
{
    int a[10], i, j, temp;

    printf("\n Enter the value of array :");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int j=0;j<10;j++){
        for(int i=j;i<9;i++){
            if(a[j]>a[i+1]){
                temp=a[j];
                a[j]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf(" %d\t", a[i]);
    }
}