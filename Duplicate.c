//Duplicate element
#include<stdio.h>
int main()
{
    int a[100],n,count=0;
    printf("Enter the size\n");
    scanf("%d",&n);
    printf("Enter the element\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
            {
                count++;
                break;
            }
        }
    }
    printf("toatal duplicate elements=%d",count);
    
}