#include<stdio.h>
int main(){
    int a[10],i,n,t=0;
    for(int i=0;i<10;i++){
        printf("\nValue=");
        scanf("%d",&a[i]);
    }
    printf("\n Enter VAlue to Search:");
    scanf("%d",&n);
    for(int i=0;i<10;i++){
        if (n==a[i]){
            t=1;
        }
    }
    if(t==1){
        printf("\n Value %d found \n",n );
    }
       else{
        printf("\n Value is not found in an array \n");

       }
       return 0; 
}