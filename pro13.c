#include<stdio.h>
#include<malloc.h>
int main(){
    int *p,i,n,sum=0;
    p=(int *)malloc(10*sizeof(int));

    for(int i=0;i<10;i++){
        printf("Value= ");
        scanf("%d",&n);

        *(p+i)=n;
    }
    for(int i=0;i<10;i++){
        sum=sum+*(p+i);
        
    }
    printf("Sum= %d\n",sum);
    free(p);
    return 0;
}
