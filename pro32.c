#include<stdio.h>

int  main(){
    int x[20],n,a,b,frist,last,mid,item,i,j,temp;

    printf("enter size of array element \n");
    scanf("%d",&n);

    printf("enter array \n");
    for(int a=0;a<n;a++){
        scanf("%d",&x[a]);

    }
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(x[j]>x[j+1]){
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    printf("Enter item for search\n");
    scanf("%d",&item);
    //binary searcg operation
    frist = 0; last =n-1;
    while(frist <=last )
    {
        mid = (frist + last )/2;
        if (x [mid]==item ){
            printf("item is found");
            break;
        }
        if(item< x [mid])
        last = mid-1;
        else
        frist = mid +1;

    }
    if(frist >last)
    printf("item is not found ");
}